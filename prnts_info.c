
void print_sock_info(int sock)
{
	struct sockaddr_in saddr;
	int  size = sizeof(saddr);
	getsockname(sock,(struct sockaddr*)&saddr,&size);
	printf("FAMILY    =%d\n",saddr.sin_family);
	printf("scr IP    =%s\n",inet_ntoa(saddr.sin_addr));
	printf("src          port           =         %d\n",(int)ntohs(saddr.sin_port));
	
	
	getpeername(sock,(struct sockaddr*)&saddr,&size);
	printf("FAMILY    =%d\n",saddr.sin_family);
	printf("scr IP    =%s\n",inet_ntoa(saddr.sin_addr));
	printf("src          port           =         %d\n",(int)ntohs(saddr.sin_port));
}
