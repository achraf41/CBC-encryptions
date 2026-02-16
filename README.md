# CBC-encryptions
encrypt a .text file and then decrypted using CBC encryption method

to run the code : 

# first modefie this line in the main.c whit the write path 

char *filename = "C:\\the path to the .txt file you one to use \\file.txt";

filename = "C:\\where do you one the encrypted file to be \\encrypted_file.bin";

filename = "C:\\where do you one the decrypted file to be \\decripted_file.bin";

# execute this two commands : 

gcc main.c cbc.c fileio.c linkedlist.c -o main.exe

.\main.exe 