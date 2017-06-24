//--------------------------------------------------------------------------------------------
//
// Generated by X-HDL VHDL Translator - Version 2.0.0 Feb. 1, 2011
// ?? 6? 20 2017 19:16:11
//
//      Input file      : 
//      Component name  : shuma
//      Author          : 
//      Company         : 
//
//      Description     : 
//
//
//--------------------------------------------------------------------------------------------


module shuma(CLK1, RST1, DATA, WEI, DUAN);
   input            CLK1;
   input            RST1;
   input [7:0]      DATA;
   output [5:0]     WEI;
   reg [5:0]        WEI;
   output [7:0]     DUAN;
   reg [7:0]        DUAN;
   
   parameter [2:0]  sta_st0 = 0,
                    sta_st1 = 1,
                    sta_st2 = 2,
                    sta_st3 = 3,
                    sta_st4 = 4,
                    sta_st5 = 5,
                    sta_st6 = 6,
                    sta_st7 = 7;
   reg [2:0]        cs;
   reg [2:0]        ns;
   reg [7:0]        MEMduan[0:9];
   reg [5:0]        MEMwei[0:5];
   always @(*) MEMduan[0] <= 8'b11000000;
   always @(*) MEMduan[1] <= 8'b11111001;
   always @(*) MEMduan[2] <= 8'b10100100;
   always @(*) MEMduan[3] <= 8'b10110000;
   always @(*) MEMduan[4] <= 8'b10011001;
   always @(*) MEMduan[5] <= 8'b10010010;
   always @(*) MEMduan[6] <= 8'b10000010;
   always @(*) MEMduan[7] <= 8'b11111000;
   always @(*) MEMduan[8] <= 8'b10001000;
   always @(*) MEMduan[9] <= 8'b10010000;
   
   always @(*) MEMwei[0] <= 6'b000001;
   always @(*) MEMwei[1] <= 6'b000010;
   always @(*) MEMwei[2] <= 6'b000100;
   always @(*) MEMwei[3] <= 6'b001000;
   always @(*) MEMwei[4] <= 6'b010000;
   always @(*) MEMwei[5] <= 6'b100000;
   
   
   always @(cs)
   begin: COM
      reg [3:0]        d[0:2];
      d = convert(DATA);
      case (cs)
         sta_st0 :
            begin
               WEI <= MEMwei[0];
               DUAN <= MEMduan[d[0]];
               ns <= sta_st1;
            end
         sta_st1 :
            begin
               WEI <= MEMwei[1];
               DUAN <= MEMduan[d[1]];
               ns <= sta_st2;
            end
         sta_st2 :
            begin
               WEI <= MEMwei[2];
               DUAN <= MEMduan[d[2]];
               ns <= sta_st3;
            end
         sta_st3 :
            begin
               WEI <= MEMwei[3];
               DUAN <= 8'b10000000;
               ns <= sta_st4;
            end
         sta_st4 :
            begin
               WEI <= MEMwei[4];
               DUAN <= 8'b10000000;
               ns <= sta_st5;
            end
         sta_st5 :
            begin
               WEI <= MEMwei[5];
               DUAN <= 8'b10000000;
               ns <= sta_st0;
            end
         default :
            begin
               WEI <= MEMwei[5];
               DUAN <= 8'b10000000;
               ns <= sta_st0;
            end
      endcase
   end
   
   always @(posedge CLK1 or posedge RST1)
   begin: REG
      if (RST1 == 1'b1)
         cs <= sta_st0;
      else 
         cs <= ns;
   end
   
endmodule



