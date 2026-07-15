#include <unistd.h>
#include <limits.h>
void ft_putnbr_fd(int n, int fd)
{
    char c;
    
    if(n == -2147483648)
    {
        write(1,"-2147483648", 11);
    }
    else if(n < 0)
    {
        write(fd, "-", 1);
        n = -n;
    }

    if(n > 9)
    {
        ft_putnbr_fd(n / 10, fd);
        ft_putnbr_fd(n % 10, fd);
    }
    else if(n > 0)
    {
        c = n + 48;
        write(fd, &c, 1);
    }


}
