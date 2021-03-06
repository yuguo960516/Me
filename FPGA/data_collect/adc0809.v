//--------------------------------------------------------------------------------------------
//
// Generated by X-HDL VHDL Translator - Version 2.0.0 Feb. 1, 2011
// ?? 6? 20 2017 19:15:58
//
//      Input file      : 
//      Component name  : adc0809
//      Author          : 
//      Company         : 
//
//      Description     : 
//
//
//--------------------------------------------------------------------------------------------


module ADC0809(D, CLK, RST, EOC, ALE, START, OE, ADDA, LOCK_T, Q);
   input [7:0]      D;
   input            CLK;
   input            RST;
   input            EOC;
   output           ALE;
   reg              ALE;
   output           START;
   reg              START;
   output           OE;
   reg              OE;
   output           ADDA;
   output           LOCK_T;
   output [7:0]     Q;
   
   parameter [2:0]  states_s0 = 0,
                    states_s1 = 1,
                    states_s2 = 2,
                    states_s3 = 3,
                    states_s4 = 4;
   reg [2:0]        cs;
   reg [2:0]        ns;
   reg [7:0]        REGL;
   reg              LOCK;
   assign ADDA = 1'b0;
   assign LOCK_T = LOCK;
   
   always @(cs or EOC)
   begin: COM
      case (cs)
         states_s0 :
            begin
               ALE <= 1'b0;
               START <= 1'b0;
               OE <= 1'b0;
               LOCK <= 1'b0;
               ns <= states_s1;
            end
         states_s1 :
            begin
               ALE <= 1'b1;
               START <= 1'b1;
               OE <= 1'b0;
               LOCK <= 1'b0;
               ns <= states_s2;
            end
         states_s2 :
            begin
               ALE <= 1'b0;
               START <= 1'b0;
               OE <= 1'b0;
               LOCK <= 1'b0;
               if (EOC == 1'b1)
                  ns <= states_s3;
               else
                  ns <= states_s2;
            end
         states_s3 :
            begin
               ALE <= 1'b0;
               START <= 1'b0;
               OE <= 1'b1;
               LOCK <= 1'b0;
               ns <= states_s4;
            end
         states_s4 :
            begin
               ALE <= 1'b0;
               START <= 1'b0;
               OE <= 1'b1;
               LOCK <= 1'b1;
               ns <= states_s0;
            end
         default :
            begin
               ALE <= 1'b0;
               START <= 1'b0;
               OE <= 1'b0;
               LOCK <= 1'b0;
               ns <= states_s0;
            end
      endcase
   end
   
   always @(posedge CLK or posedge RST)
   begin: REG
      if (RST == 1'b1)
         cs <= states_s0;
      else 
         cs <= ns;
   end
   
   always @(posedge LOCK)
   begin: LATCH1
      
         REGL <= D;
   end
   assign Q = REGL;
   
endmodule
