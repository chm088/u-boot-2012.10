#include <asm/arch/s3c6410.h>
#include <asm/io.h>

int led_chg(unsigned gpio)
{
	unsigned port, l;

	port = ELFIN_GPIO_BASE + GPMDAT_OFFSET;
	l = readl(port);

	switch (gpio)
	{
	case 0:
	case 1:
	case 2:
	case 3:
		l ^= ~(0x01<<gpio);
		break;

	default:
		return -1;
	}
	writel(l, port);
	return 0;
}

void led_set(unsigned gpio, int value)
{
	unsigned port, l;

	port = ELFIN_GPIO_BASE + GPMDAT_OFFSET;
	l = readl(port);

	switch (gpio)
	{
	case 0:
	case 1:
	case 2:
	case 3:
		if(value == 0)
			l &= ~(0x01<<gpio);
		else
			l |= (0x01<<gpio);
		break;

	default:
//		return -1;
		break;
	}

	writel(l, port);
//	return 0;
}
