# Server 
import socket

vigenere_key: str = "sic"


def vig_enc(nonce: str) -> str:

    encrypted: str = ""
    for i in range(len(nonce)):
        
        ch1 = ord('a') + ord(nonce[i])
        ch2 = ord('a') + ord(vigenere_key[i%len(vigenere_key)])
                
        encrypted += chr((ch1 + ch2)%26)

    return encrypted


if __name__ == '__main__':

    print("Server: ")
    s = socket.socket(socket.AF_INET,socket.SOCK_STREAM)

    host = socket.gethostname()  # Get local machine name
    port = 8081
    
    s.bind((host, port))
    s.listen(5)

    c, addr = s.accept()
    print('Got connection from', addr)

    while True:
        
        nonce: str = str(c.recv(1024))
        print(f"<-- nonce: {nonce}")
        encrypted_nonce: str = vig_enc(nonce[2:-1])
        print(f"--> Encrypted nonce: {encrypted_nonce}")
        
        break
        c.sendall(bytes(encrypted_nonce, "ascii"))
    
        break

    c.close()