#include <REGX51.H>
sbit drp=P2^0;
sbit drn=P2^1;
sbit rs=P2^5;
sbit rw=P2^6;
sbit en=P2^7;
void lcddat(unsigned char);
void lcdcmd(unsigned char);
void lcddis(unsigned char *);
void lcd_init();
void serial_init();
void check();
void delay();
void mdelay();
unsigned char rfid[12] , v1;
void main(){
	print
	lcddis("RFID BASED CAR");
	lcdcmd(0xc0);
	drp=drn=0;
	serial_init();
	lcd_init();
	lcddis("RFID BASED CAR");
	lcdcmd(0xc0);
	lcddis("PARKING SYSTEM");
	mdelay();
	lcdcmd(0x01);
	while(1)
	{
		lcdcmd(0x01);
		lcddis("SWIPE YOUR CARD");
		for(v1=0;v1<12;v1++)
		{
			while(RI==0);
			rfid[v1]=SBUF;
			RI=0;
			SBUF=rfid[v1];
			while(TI==0);
			TI=0;
		}
		check();
	}
}
	//fjkl. . . 
	void check()
	{
		if(rfid[0]=='1' && rfid[1]=='A' && rfid[2]=='3' && rfid[3]=='4' && rfid[4]=='6' && rfid[5]=='5' && 
			rfid[6]=='B' && rfid[7]=='8' && rfid[8]=='9' && rfid[9]=='3' && rfid[10]=='5' && rfid[11]=='6')
		{
			lcdcmd(0x01);
			lcddis("ASSOCIATION MEMBER");
			lcdcmd(0xc0);
			lcddis("SHARMA SLOT 101");
			delay();
			delay();
			lcdcmd(0x01);
			drp=1;
			drn=0;
			lcddis("DOOR OPENING");
			lcdcmd(0xc0);
			lcddis("ALLOW INSIDE");
			mdelay();
			drp=0;drn=0;
		}
		else if(rfid[0]=='3' && rfid[1]=='2' && rfid[2]=='4' && rfid[3]=='5' && rfid[4]=='F' && rfid[5]=='R' && 
			rfid[6]=='6' && rfid[7]=='7' && rfid[8]=='8' && rfid[9]=='6' && rfid[10]=='A' && rfid[11]=='1')
		{
			lcdcmd(0x01);
			lcddis("ASSOCIATION MEMBER");
			lcdcmd(0xc0);
			lcddis("MURTHY SLOT 101");
			delay();
			delay();
			lcdcmd(0x01);
			drp=1;
			drn=0;
			lcddis("DOOR OPENING");
			lcdcmd(0xc0);
			lcddis("ALLOW INSIDE");
			mdelay();
			drp=0;drn=0;
		}
		else if(rfid[0]=='2' && rfid[1]=='3' && rfid[2]=='4' && rfid[3]=='R' && rfid[4]=='5' && rfid[5]=='6' && 
			rfid[6]=='Y' && rfid[7]=='7' && rfid[8]=='1' && rfid[9]=='2' && rfid[10]=='9' && rfid[11]=='7')
		{
			lcdcmd(0x01);
			lcddis("ASSOCIATION MEMBER");
			lcdcmd(0xc0);
			lcddis("MURTHY SLOT 101");
			delay();
			delay();
			lcdcmd(0x01);
			drp=1;
			drn=0;
			lcddis("DOOR OPENING");
			lcdcmd(0xc0);
			lcddis("ALLOW INSIDE");
			mdelay();
			drp=0;drn=0;
		}
		else if(rfid[0]=='1' && rfid[1]=='4' && rfid[2]=='5' && rfid[3]=='6' && rfid[4]=='7' && rfid[5]=='8' && 
			rfid[6]=='H' && rfid[7]=='A' && rfid[8]=='3' && rfid[9]=='4' && rfid[10]=='E' && rfid[11]=='C')
		{
			lcdcmd(0x01);
			lcddis("ASSOCIATION MEMBER");
			lcdcmd(0xc0);
			lcddis("MURTHY SLOT 101");
			delay();
			delay();
			lcdcmd(0x01);
			drp=1;
			drn=0;
			lcddis("DOOR OPENING");
			lcdcmd(0xc0);
			lcddis("ALLOW INSIDE");
			mdelay();
			drp=0;drn=0;
		}
		else
		{
			lcdcmd(0x01);
			lcddis("OUTSIDE PERSON");
			lcdcmd(0xc0);
			lcddis("NO SLOT FOR YOU");
			mdelay();
		}
	}
	//fjkl. . . . .
	void lcd_init()
	{
		lcdcmd(0x38);
		lcdcmd(0x01);
		lcdcmd(0x10);
		lcdcmd(0x0c);
		lcdcmd(0x80);
	}
	void lcdcmd(unsigned char val)
	{
		P1=val;
		rs=0;
		rw=0;
		en=1;
		delay();
		en=0;
	}
	void lcddat(unsigned char val)
	{
		P1=val;
		rs=1;
		rw=0;
		en=1;
		delay();
		en=0;		
	}
	void lcddis(unsigned char *s)
	{
		unsigned char w;
		for(w=0;s[w]!='\0';w++)
		{
			lcddat(s[w]);
		}
	}
	void serial_init()
	{
		SCON=0X50;
		TMOD=0X20;
		TH1=-3;
		TR1=1;
	}
	void delay()
	{
		unsigned int v5;
		for(v5=0;v5<5000;v5++);
	}
	void mdelay()
	{
		unsigned int v6,v7;
		for(v6=0;v6<2;v6++)
		{
		for(v7=0;v7<3000;v7++);
		}
	}
	
