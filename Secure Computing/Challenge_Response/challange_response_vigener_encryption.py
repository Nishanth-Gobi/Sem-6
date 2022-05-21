Nonce="agfgfytftyritftyturttysyfiyuyttc"

vigener="sic"

N=len(Nonce)
n=len(vigener)

vigener_key=""

if(N%n) == 0:
    for i in range(0,(N//n)+1):
        vigener_key+=vigener

else:
    for i in range(0,N//n):
        vigener_key+=vigener
    for j in range(0,N%n):
        vigener_key+=vigener[j]

print(Nonce)
print(vigener_key)

alphabet = {}

for i in range(26):
    alphabet[i] = chr(ord('a')+i)

alphabet1 = {}

for key, val in alphabet.items():
    alphabet1[val] = key
    
encrypted=""

for i in range (0,len(Nonce)):
        #ch=Nonce[i]
        num=alphabet1[Nonce[i]]
        ch1=vigener_key[i]
        num1=alphabet1[ch1]
        numAns=(num+num1)%26
        encrypted+=alphabet[(num+num1)%26]
        
    