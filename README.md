# vr
# Stager.c

A stager is a program that connect to a server using a socket, it the receive a 4 bytes int representing size
then it receive a binary input with size = size

Then in pass the socket_fd to the received binary, using 0xBF (asm mov)
it then cast the buffer of receiver binary into a function pointer

the it calls it function using CreatThread

The binary can be Absolutely any program

result : 0/64 Virustotal - with a windows/meterpreter/revese_tcp from metasploit

#ded.zip

Zip archive hold a program that read and decrypt every recorded password in chrome and write them to a file in Temp/result (windows)
