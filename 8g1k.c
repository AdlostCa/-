#include ".\CORE\STC8Ax_REG.H"
sbit PWM=P2^1;  //���������ź��߽ӵ�I/O��
void UartInit(void)		//9600bps@11.0592MHz
{
	SCON = 0x50;		//8λ����,�ɱ䲨����
	AUXR |= 0x40;		//��ʱ��ʱ��1Tģʽ
	AUXR &= 0xFE;		//����1ѡ��ʱ��1Ϊ�����ʷ�����
	TMOD &= 0x0F;		//���ö�ʱ��ģʽ
	TL1 = 0xE0;		//���ö�ʱ��ʼֵ
	TH1 = 0xFE;		//���ö�ʱ��ʼֵ
	ET1 = 0;		//��ֹ��ʱ��%d�ж�
	TR1 = 1;		//��ʱ��1��ʼ��ʱ
}
void send(char dat){
SBUF=dat;
while(!TI){
	TI=0;
}
}

void dalay(int ms){
	int i=0,j=0;
	for (i=0;i<5000;i++){
		for (j=0;j<ms;j++);
	}
}
void Delay(unsigned char i)   //12MHz ��ʱ����  
{
    unsigned char a,b;        //�ö���ʱ����Delay(1)=0.5ms
    for(;i>0;i--)
      for(b=71;b>0;b--)
        for(a=2;a>0;a--);
}
void zero(void) //0�� �ӳ���
{   
        PWM=1;
        Delay(1);       //�ߵ�ƽ Delay(1)=0.5ms����Ϊ����Ϊ20ms�����Ե͵�ƽ����19.5ms 
        PWM=0;
        Delay(39);      //�͵�ƽ Delay(39)=19.5ms
}
void three(void) //135�� �ӳ���
{
        PWM=1;
        Delay(4);       //�ߵ�ƽ Delay(4)=2ms
        PWM=0;
        Delay(36);      //�͵�ƽ 18ms
}

sbit l1=P0^4;
sbit l2=P0^5;
sbit l3=P0^6;
sbit l4=P0^7;
sbit k1=P1^0;
sbit key=P5^1;
int flag=1;
void main(){
	
//	P_SW1 &=0x0f;
//	P_SW1 |=0x80;
	P0M0=0;
	P0M1=0;
P2M0=0;
P2M1=0; 
	UartInit();

	 if(SBUF=='1')   //������P3^1�ڡ������������
		{
		  Delay(20);   
			 if(SBUF=='1'){three();  //����������£����ö��90���ӳ���ʵ��ת��90�ȡ�
l2=0;			 }    
             
		}
 
		 else         //����
		    zero();   //���Ϊ0��
    }
	
	


//	
//RI = 0;//��������жϱ�־λ	
//	SBUF = '6';//�����յ������ݷŻط��ͻ�����
//	while(!TI);//�ȴ������������
//	TI = 0;//��������жϱ�־λ
//	
