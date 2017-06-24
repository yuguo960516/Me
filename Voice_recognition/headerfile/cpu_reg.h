
#define int0_VAL       1<<0
#define tint_VAL       1<<3
#define rint_VAL       1<<4
#define xint_VAL       1<<5

#define SPCR10_VAL     0x0000
#define SPCR20_VAL     0x0200
//2 words per frame
#define RCR10_VAL      0x0140
#define RCR20_VAL      0x04
//2 words per frame
#define XCR10_VAL      0x0140
#define XCR20_VAL      0x04
#define PCR0_VAL       0x01


#define SRGR1_VAL2      (23<<8)+47
#define SRGR1_VAL1      (23<<8)+47

//֡����=48��CLK��CPU��ʱ����������FSG����
#define SRGR2_VAL1      0x3000+47

//����֡ͬ����ʱ�����ڲ�������11 9λ=1)
//����֡ͬ����ʱ�����ⲿ������10 8λ=0)
//֡ͬ������Ч����2 3λ=0����  �½�����Ч��2 3λ=1��
//ʱ����������Ч�����2λ=0�����½�����Ч�����2λ=1��
//�������óɴ��ڣ�
#define PCR_VAL1       0x0a03

//DX is on(7=True) 
//RINT by RRDY
#define SPCR1_VAL1     0x0080

// һ֡2���֣�ÿ��24bit
#define XCR1_VAL1      0x0180
// ����֡����ѹ����0-bit�ӳ�
#define XCR2_VAL1      0x0004

// һ֡2���֣�ÿ��24bit
#define RCR1_VAL1      0x0180
// ����֡����ѹ����0-bit�ӳ�
#define RCR2_VAL1      0x0004


//McBSP Memory Mapped Registers
#define CLKMD         (unsigned int *)0x58
#define SWCR          (unsigned int *)0x2b
#define IMR           (unsigned int *)0x00

#define SPSA0         (unsigned int *)0x38
#define SPSD0         (unsigned int *)0x39
#define DRR20         (unsigned int *)0x20
#define DRR10         (unsigned int *)0x21
#define DXR20         (unsigned int *)0x22
#define DXR10         (unsigned int *)0x23

#define SPSA1         (unsigned int *)0x48
#define SPSD1         (unsigned int *)0x49
#define DRR21         (unsigned int *)0x40
#define DRR11         (unsigned int *)0x41
#define DXR21         (unsigned int *)0x42
#define DXR11         (unsigned int *)0x43

// McBSP Subaddresed Registers
#define SPCR1          0x00
#define SPCR2          0x01
#define RCR1           0x02
#define RCR2           0x03
#define XCR1           0x04
#define XCR2           0x05
#define SRGR1          0x06
#define SRGR2          0x07
#define PCR            0x0E


void delay(int k);
void McBsp0_init();



