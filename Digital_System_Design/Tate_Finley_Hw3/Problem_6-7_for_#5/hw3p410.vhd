----------------------------------
-- Tate Finley
-- ECE 3140
-- HW3 Problem 6
--
-- Implementation for problem 4.7

--Convert Gray code to BCD
----------------------------------

library IEEE;
use IEEE.STD_LOGIC_1164.all;

-- This design accepts a four-bit
-- unsigned binary number as input (in3
-- is MSb and in0 is LSb)
-- The design has four output Booleans:
--  out_47A: Msb of four bit output for BCD
--  out_47B: Next Msb of four bit output for BCD
--  out_47C: Third bit of four bit output for BCD
--  out_47D: Lsb of four bit output for BCD

entity hw3p410 is port(
  in3: in std_logic;
  in2: in std_logic;
  in1: in std_logic;
  in0: in std_logic;
  out_410A: out std_logic;
  out_410B: out std_logic;
  out_410C: out std_logic;
  out_410D: out std_logic);  
end entity hw3p410;

-- ---------------------------------------
--   THE Architecture OF YOUR DESIGN GOES IN THIS
--    SECTION. 
-- ---------------------------------------
architecture Logic410 of hw3p410 is
  
  component my_Output is
	port( x: in std_logic;
  	  	  y: out std_logic);
  end component;

  
  component my_Xor2 is
	port( x,y: in std_logic;
  	  		z: out std_logic);
  end component;

  component my_Or2 is
	port( x,y: in std_logic;
  	  		z: out std_logic);
  end component;
  
  signal temp1, temp2 : std_logic;
  
  begin
    --Implement logic for outputs
    U0: my_Or2 port map (x=>in0, y=>in1, z=>temp1);
    U1: my_Or2 port map (x=>in2, y=>temp1, z=>temp2);
    
    --Implement outputs
    U2: my_Output port map (x=>in0, y=>out_410D);
    U3: my_Xor2 port map (x=>in0, y=>in1, z=>out_410C);
    U4: my_Xor2 port map (x=>temp1, y=>in2, z=>out_410B);
    U5: my_Xor2 port map (x=>temp2, y=>in3, z=>out_410A);
       
end architecture Logic410;