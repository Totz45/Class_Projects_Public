-- ------------------------------------------------------
--   Tate Finley
--   ECE 3140
--   HW3 Problems 4.2-4.10 -> unit file
-- -------------------------------------------------------

-- --------------------------------------
--    Output 
-- --------------------------------------

library IEEE;
use IEEE.STD_LOGIC_1164.all;

entity my_Output is
port( x: in std_logic;
  	  y: out std_logic);
end my_Output;

architecture LogicOut of my_Output is
begin
    y <= x;
end LogicOut;

-- --------------------------------------
--    Inverter 
-- --------------------------------------

library IEEE;
use IEEE.STD_LOGIC_1164.all;

entity my_Inv is
port( x: in std_logic;
  	  y: out std_logic);
end my_Inv;

architecture LogicInv of my_Inv is
begin
    y <= not x;
end LogicInv;

-- --------------------------------------
--    2-Input And Gate 
-- --------------------------------------

library IEEE;
use IEEE.STD_LOGIC_1164.all;

entity my_And2 is
port( x,y: in std_logic;
  	  z: out std_logic);
end my_And2;

architecture LogicAnd2 of my_And2 is
begin
    z <= x and y;
end LogicAnd2;

-- --------------------------------------
--    3-Input And Gate 
-- --------------------------------------

library IEEE;
use IEEE.STD_LOGIC_1164.all;

entity my_And3 is
port( w,x,y: in std_logic;
  	  z: out std_logic);
end my_And3;

architecture LogicAnd3 of my_And3 is
begin
    z <= w and x and y;
end LogicAnd3;

-- --------------------------------------
--    4-Input And Gate 
-- --------------------------------------

library IEEE;
use IEEE.STD_LOGIC_1164.all;

entity my_And4 is
port( w,x,y,z: in std_logic;
  	  a: out std_logic);
end my_And4;

architecture LogicAnd4 of my_And4 is
begin
    a <= w and x and y and z;
end LogicAnd4;

-- --------------------------------------
--    2-Input Nand Gate 
-- --------------------------------------

library IEEE;
use IEEE.STD_LOGIC_1164.all;

entity my_Nand2 is
port( x,y: in std_logic;
  	  z: out std_logic);
end my_Nand2;

architecture LogicNand2 of my_Nand2 is
begin
    z <= x nand y;
end LogicNand2;

-- --------------------------------------
--    2-Input Or Gate 
-- --------------------------------------

library IEEE;
use IEEE.STD_LOGIC_1164.all;

entity my_Or2 is
port( x,y: in std_logic;
  	  z: out std_logic);
end my_Or2;

architecture LogicOr2 of my_Or2 is
begin
    z <= x or y;
end LogicOr2;

-- --------------------------------------
--    3-Input Or Gate 
-- --------------------------------------

library IEEE;
use IEEE.STD_LOGIC_1164.all;

entity my_Or3 is
port( w,x,y: in std_logic;
  	  z: out std_logic);
end my_Or3;

architecture LogicOr3 of my_Or3 is
begin
    z <= w or x or y;
end LogicOr3;

-- --------------------------------------
--    4-Input Or Gate 
-- --------------------------------------

library IEEE;
use IEEE.STD_LOGIC_1164.all;

entity my_Or4 is
port( w,x,y,z: in std_logic;
  	  a: out std_logic);
end my_Or4;

architecture LogicOr4 of my_Or4 is
begin
    a <= w or x or y or z;
end LogicOr4;

-- --------------------------------------
--    2-Input Xor Gate 
-- --------------------------------------

library IEEE;
use IEEE.STD_LOGIC_1164.all;

entity my_Xor2 is
port( x,y: in std_logic;
  	  z: out std_logic);
end my_Xor2;

architecture LogicXor2 of my_Xor2 is
begin
    z <= x xor y;
end LogicXor2;

-- --------------------------------------
--    3-Input Xor Gate 
-- --------------------------------------

library IEEE;
use IEEE.STD_LOGIC_1164.all;

entity my_Xor3 is
port( w,x,y: in std_logic;
  	  z: out std_logic);
end my_Xor3;

architecture LogicXor3 of my_Xor3 is
begin
    z <= w xor x xor y;
end LogicXor3;

-- --------------------------------------
--    4-Input Xor Gate 
-- --------------------------------------

library IEEE;
use IEEE.STD_LOGIC_1164.all;

entity my_Xor4 is
port( w,x,y,z: in std_logic;
  	  a: out std_logic);
end my_Xor4;

architecture LogicXor4 of my_Xor4 is
begin
    a <= w xor x xor y xor z;
end LogicXor4;