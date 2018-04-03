

ssize_t readall(int fd, const void *buf, size_t nbyte)
{
	ssize_t nreaden = 0, n;
	do {
		if ((n = read(fd, &((char *)buf)[nreaden], nbyte - nreaden)) == -1) {
			if(errno == EINTR)
				continue;
			else
				return -1;
		}
	if(n == 0) {
		return nreaden;
	}
	nreaden += n;
	}while(nreaden < nbyte);
	return nreaden;
}
