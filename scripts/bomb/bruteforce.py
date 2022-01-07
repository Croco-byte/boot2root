from pwn import *

phase_1 = b"Public speaking is very easy."
phase_2 = b"1 2 6 24 120 720"
phase_3 = b"1 b 214"
phase_4 = b"9"
phase_5 = b"opukmq"
payload = b"4 "

for two in range(1, 7) :
    for three in range(1, 7):
        for four in range(1, 7):
            for five in range(1, 7):
                for six in range(1, 7):
                    payload = "4 "
                    payload += str(two) + " "
                    payload += str(three) + " "
                    payload += str(four) + " "
                    payload += str(five) + " "
                    payload += str(six)
                    print("[*] Trying " + payload)




                    p = process("./bomb")
                    p.recvline()
                    p.recvline()

                    p.sendline(phase_1)
                    p.recvline()

                    p.sendline(phase_2)
                    p.recvline()

                    p.sendline(phase_3)
                    p.recvline()

                    p.sendline(phase_4)
                    p.recvline()

                    p.sendline(phase_5)
                    p.recvline()

                    p.sendline(payload.encode())
                    p.recvline()
                    result = p.recvline()
                    p.close()
                    if (result.find(b"BOOM") != -1):
                        print("[-] Not found")
                    else:
                        print("[+] FOUND : " + payload)
                        quit()



