----------------------------------
-- Tate Finley
-- ECE 3140
-- HW3 Problem 6
--
-- Implementation for problem 4.9

--Convert BCD to seven-segment
----------------------------------

library IEEE;
use IEEE.STD_LOGIC_1164.all;

-- This design accepts a four-bit
-- unsigned binary number as input (in3
-- is MSb and in0 is LSb)
-- The design has four output Booleans:
--  out_49A: Msb of four bit output for seven
--  segment
--  out_49B: Next Msb of four bit output for 
--  seven-segment
--  out_49C: Third bit of four bit output for
--  seven-segment
--  out_49D: Lsb of four bit output for seven
--  segment

entity hw3p49 is port(
  in3: in std_logic;
  in2: in std_logic;
  in1: in std_logic;
  in0: in std_logic;
  out_49A: out std_logic;
  out_49B: out std_logic;
  out_49C: out std_logic;
  out_49D: out std_logic;
  out_49E: out std_logic;
  out_49F: out std_logic;
  out_49G: out std_logic);  
end entity hw3p49;

-- ---------------------------------------
--   THE Architecture OF YOUR DESIGN GOES IN THIS
--    SECTION. 
-- ---------------------------------------
architecture Logic49 of hw3p49 is
  
  component my_Inv is
	port( x: in std_logic;
  	  	  y: out std_logic);
  end component;

  component my_And2 is
	port( x,y: in std_logic;
  	  		z: out std_logic);
  end component;

  component my_And3 is
	port( w,x,y: in std_logic;
  	  		z: out std_logic);
  end component;
  
  component my_And4 is
	port( w,x,y,z: in std_logic;
  	  		a: out std_logic);
  end component;
  
  component my_Or2 is
	port( x,y: in std_logic;
  	  		z: out std_logic);
  end component;

  component my_Or3 is
	port( w,x,y: in std_logic;
  	  		z: out std_logic);
  end component;
  
  component my_Or4 is
	port( w,x,y,z: in std_logic;
  	  		a: out std_logic);
  end component;
  
  signal in3bar, in2bar, in1bar, in0bar : std_logic; 
  signal temp0, temp1, temp2, temp3, temp4 : std_logic;
  signal temp5, temp6, temp7, temp8, temp9 : std_logic;
  signal temp10, temp11, temp12, temp13, temp14 : std_logic;
  
  begin
    --Invert each output to use with combinational logic
    U0: my_Inv port map (x=>in3, y=>in3bar);
    U1: my_Inv port map (x=>in2, y=>in2bar);
    U2: my_Inv port map (x=>in1, y=>in1bar);
    U3: my_Inv port map (x=>in0, y=>in0bar);
    
    --Implement logic that needs 2-Input And Gates
    U4: my_And2 port map (x=>in3bar, y=>in1, z=>temp0);
    U5: my_And2 port map (x=>in2bar, y=>in1bar, z=>temp4);
    U6: my_And2 port map (x=>in3bar, y=>in2bar, z=>temp5);
    U7: my_And2 port map (x=>in3bar, y=>in2, z=>temp8);
    
    --Implement logic that needs 3-Input And Gates
    U10: my_And3 port map (w=>in3bar, x=>in2, y=>in0, z=>temp1);
    U11: my_And3 port map (w=>in3, x=>in2bar, y=>in1bar, z=>temp2);
    U12: my_And3 port map (w=>in2bar, x=>in1bar, y=>in0bar, z=>temp3);
    U13: my_And3 port map (w=>in3bar, x=>in1bar, y=>in0bar, z=>temp6);
    U14: my_And3 port map (w=>in3bar, x=>in1, y=>in0, z=>temp7);
    U15: my_And3 port map (w=>in3bar, x=>in2bar, y=>in1, z=>temp9);
    U16: my_And3 port map (w=>in3bar, x=>in1, y=>in0bar, z=>temp10);
    U17: my_And3 port map (w=>in3bar, x=>in2, y=>in0bar, z=>temp12);
    U18: my_And3 port map (w=>in3bar, x=>in2, y=>in1bar, z=>temp13);
    
    --Implement four input and gate logic
    U19: my_And4 port map (w=>in3bar, x=>in2, y=>in1bar, z=>in0, a=>temp11);
    
    --Implement output for segments using 4 input or gates
    U20: my_Or4 port map (w=>temp0, x=>temp1, y=>temp2, z=>temp3, a=>out_49A);
    U21: my_Or4 port map (w=>temp4, x=>temp5, y=>temp6, z=>temp7, a=>out_49B);
    U22: my_Or4 port map (w=>temp2, x=>temp6, y=>temp12, z=>temp13, a=>out_49F);
    U23: my_Or4 port map (w=>temp2, x=>temp9, y=>temp10, z=>temp13, a=>out_49G); 
     
    --Implement output for segment C using 3 input or gate 
    U24: my_Or3 port map (w=>temp4, x=>temp7, y=>temp8, z=>out_49C); 
    
    --Implement output for segment D have 5 inputs to or
    U25: my_Or3 port map (w=>temp2, x=>temp3, y=>temp14, z=>out_49D);
    U26: my_Or3 port map (w=>temp9, x=>temp10, y=>temp11, z=>temp14);
    
    --Implement output for segment E using 2 input or gate
    U27: my_Or2 port map (x=>temp3, y=>temp10, z=>out_49E);
    
end architecture Logic49;