#include <netdb.h>
#include <netinet/in.h>
#include <string.h>

int get_ip_address(const char *name, in_addr_t *out,
				   char *canon_name, size_t canon_name_size)
{
	struct addrinfo hints, *result;
	int errcode;

	memset(&hints, 0, sizeof(hints));
	hints.ai_family = AF_INET;
	hints.ai_flags |= AI_CANONNAME;

	errcode = getaddrinfo(name, NULL, &hints, &result);
	if (errcode != 0)
	{
		return errcode;
	}

	*out = ((struct sockaddr_in *) result->ai_addr)->sin_addr.s_addr;
	if (canon_name)
	{
		strncpy(canon_name, result->ai_canonname, canon_name_size);
	}

	freeaddrinfo(result);

	return 0;
}

int get_dns_record(in_addr_t ip, char *host, size_t host_len)
{
	struct help {
		in_addr_t addr;
		char hostname[NI_MAXHOST];
	};
	static struct help stg[10] = {0};
	static int count = 0;

	for (int i = 0; i < count; i++)
	{
		if (stg[i].addr == ip)
		{
			strncpy(host, stg[i].hostname, host_len);
			return 0;
		}
	}

	struct sockaddr_in addr;
	int ret_code;
	memset(&addr, 0, sizeof addr);
	addr.sin_family = AF_INET;
	addr.sin_addr.s_addr = ip;

	ret_code = getnameinfo((struct sockaddr *) &addr,
						   sizeof addr,
						   host, host_len,
						   NULL, 0, 0);

	if (ret_code != 0)
	{
		return ret_code;
	}

	if (count < 10)
	{
		stg[count].addr = ip;
		strncpy(stg[count].hostname, host, NI_MAXHOST);
		count++;
	}

	return 0;
}
