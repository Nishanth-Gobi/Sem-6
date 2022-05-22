import socket
# import random 
# import string


vigenere_key: str = "sic"
N: int = 10

def vig_dec(encrypted_nonce: str) -> str: 

    decrypted: str =""
    for i in range(len(encrypted_nonce)):
            
            ch1: int = ord('a') + ord(encrypted_nonce[i])
            ch2: int = ord('a') + ord(vigenere_key[i%len(vigenere_key)])
            
            decrypted += chr((ch1 - ch2)%26)
            
    return decrypted


if __name__ == '__main__':

    print("Client: ")
    c = socket.socket()
    host = socket.gethostname() # Get local machine name
    port = 8081
    
    c.connect((host, port))
    
    while True:
        
        # nonce = ''.join(random.choices(string.ascii_uppercase + string.digits, k = N))
        nonce: str = "Youareanass"
        c.send(bytes(nonce, "ascii"))
        print(f"--> nonce: {nonce}")
        
        encrypted_nonce:str = str(c.recv(1024))
        print(f"<-- encrypted_nonce: {encrypted_nonce}")
        decrypted_nonce:str = vig_dec(encrypted_nonce[2:-1])
        
        print("*** Auth successful ***" if nonce==decrypted_nonce else "*** Auth Failure ***")
        break
    
    c.close()