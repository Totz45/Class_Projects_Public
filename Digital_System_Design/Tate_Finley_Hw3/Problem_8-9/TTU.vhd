-- --------------------------------------  
--
--  BASIC VHDL LOGIC GATES PACKAGE
--
--  (C) 2018, 2019 JW BRUCE 
--  TENNESSEE TECH UNIVERSITY 
--
-- ----------------------------------------
--      DO NOT MODIFY THIS FILE!!!!!!!!!
-- ----------------------------------------
-- REVISION HISTORY
-- ----------------------------------------
-- Rev 0.1 -- Created        (JWB Nov.2018)
-- Rev 0.2 -- Refactored into package
--                           (JWB Nov.2018)
-- Rev 0.3 -- Added more combinational
--            gates and the first sequential
--            logic primitives (SR latch & FF)
--                           (JWB Dec.2018)
-- Rev 0.4 -- Clean up some and prepared
--            for use in the Spring 2019
--            semester
--                           (JWB Feb.2019)
-- Rev 0.5 -- Created better design example
--            for use in the Spring 2019
--            semester
--                           (JWB Feb.2019)
-- Rev 0.6 -- Added some behavioral combi
--            logic building blocks
--                           (JWB Sept.2019)

--
-- ================================================
-- Package currently contains the following gates:
-- ================================================
--  COMBINATIONAL               SEQUENTIAL
--    inv                         SR 
--    orX
--    norX
--    andX
--    nandX
--    xorX
--    xnorX
--
--  where X is 2, 3, 4 and
--    denotes the number of inputs
-- ==================================

-- --------------------------------------  
library IEEE;
use IEEE.STD_LOGIC_1164.all;
--- -------------------------------------  

-- EXAMPLE 1 : package and package body definition

package TTU is
  constant Size: Natural; -- Deferred constant
  subtype Byte is STD_LOGIC_VECTOR(7 downto 0);
  -- Subprogram declaration...
  function PARITY (V: Byte) return STD_LOGIC;
  function MAJ4 (x1: STD_LOGIC; x2:STD_LOGIC; x3:STD_LOGIC;x4:STD_LOGIC) return STD_LOGIC;
end package TTU;

package body TTU is
  constant Size: Natural := 16;
  -- Subprogram body...
  function PARITY (V: Byte) return STD_LOGIC is
    variable B: STD_LOGIC := '0';
  begin
    for I in V'RANGE loop
      B := B xor V(I);
    end loop;
    return B;
  end function PARITY;
  
  function MAJ4 (x1: STD_LOGIC;x2:STD_LOGIC;x3:STD_LOGIC;x4:STD_LOGIC) return STD_LOGIC is
    variable tmp: STD_LOGIC_VECTOR(3 downto 0);
    variable retval: STD_LOGIC;
  begin
    tmp := x1 & x2 & x3 & x4;
    
    if (tmp = "1110") then
      retval := '1';
    elsif (tmp = "1101") then
      retval := '1';
    elsif (tmp = "1011") then      
      retval := '1';
    elsif (tmp = "0111") then      
      retval := '1';
    elsif (tmp = "1111") then      
      retval := '1';
    else      
      retval := '0';
    end if;
    return retval;
  end function MAJ4;
  
end package body TTU;

----------------------------------------  
library IEEE;
use IEEE.STD_LOGIC_1164.all;
use work.TTU.all;

entity EX_PACKAGE is port(
  A  :  in Byte;
  Y  : out STD_LOGIC);
end entity EX_PACKAGE;

architecture A1 of EX_PACKAGE is
  begin
    Y <= PARITY(A);
end architecture A1;

----------------------------------------  
-- The INVERTER
library IEEE;
use IEEE.STD_LOGIC_1164.all;
use work.TTU.all;

entity INV is
port(
  x: in STD_LOGIC;
  y: out STD_LOGIC);
end INV;

architecture RTL of INV is
begin
  process(x) is
  begin
    y <= not x;
  end process;
end RTL;

-- ------------------------------------
-- OR GATES

----------------------------------------  
-- The TWO-INPUT OR GATE
library IEEE;
use IEEE.STD_LOGIC_1164.all;
use work.TTU.all;

entity OR2 is
port(
  x0: in std_logic;
  x1: in std_logic;
  y: out std_logic);
end OR2;

architecture RTL of OR2 is
begin
  process(x0, x1) is
  begin
    y <= x0 or x1;
  end process;
end RTL;

-- The THREE-input OR gate
library IEEE;
use IEEE.STD_LOGIC_1164.all;
use work.TTU.all;

entity OR3 is
port(
  x0: in std_logic;
  x1: in std_logic;
  x2: in std_logic;
  y: out std_logic);
end OR3;

architecture RTL of or3 is
begin
  process(x0, x1, x2) is
  begin
    y <= x1 or x2 or x0;
  end process;
end RTL;

-- The FOUR-input OR gate
library IEEE;
use IEEE.STD_LOGIC_1164.all;
use work.TTU.all;

entity OR4 is
port(
  x0: in std_logic;
  x1: in std_logic;
  x2: in std_logic;
  x3: in std_logic;
  y: out std_logic);
end OR4;

architecture RTL of OR4 is
begin
  process(x1, x2, x3, x0) is
  begin
    y <= x1 or x2 or x3 or x0;
  end process;
end RTL;

-- ------------------------------------
-- AND GATES

-- The TWO-input AND gate
library IEEE;
use IEEE.STD_LOGIC_1164.all;
use work.TTU.all;

entity AND2 is
port(
  x0: in std_logic;
  x1: in std_logic;
  y: out std_logic);
end AND2;

architecture RTL of AND2 is
begin
  process(x1, x0) is
  begin
    y <= x1 and x0;
  end process;
end RTL;

-- The THREE-input AND gate
library IEEE;
use IEEE.STD_LOGIC_1164.all;
use work.TTU.all;

entity AND3 is
port(
  x0: in std_logic;
  x1: in std_logic;
  x2: in std_logic;
  y: out std_logic);
end AND3;

architecture RTL of AND3 is
begin
  process(x1, x2, x0) is
  begin
    y <= x1 and x2 and x0;
  end process;
end RTL;

-- The FOUR-input AND gate
library IEEE;
use IEEE.STD_LOGIC_1164.all;
use work.TTU.all;

entity AND4 is
port(
  x0: in std_logic;
  x1: in std_logic;
  x2: in std_logic;
  x3: in std_logic;
  y: out std_logic);
end AND4;

architecture RTL of AND4 is
begin
  process(x1, x2, x3, x0) is
  begin
    y <= x1 and x2 and x3 and x0;
  end process;
end RTL;

-- ------------------------------------
-- XOR GATES

-- The TWO-input XOR gate
library IEEE;
use IEEE.STD_LOGIC_1164.all;
use work.TTU.all;

entity XOR2 is
port(
  x0: in std_logic;
  x1: in std_logic;
  y: out std_logic);
end XOR2;

architecture RTL of XOR2 is
begin
  process(x1, x0) is
  begin
    y <= x1 xor x0;
  end process;
end RTL;

-- The THREE-input XOR gate
library IEEE;
use IEEE.STD_LOGIC_1164.all;
use work.TTU.all;

entity XOR3 is
port(
  x0: in std_logic;
  x1: in std_logic;
  x2: in std_logic;
  y: out std_logic);
end XOR3;

architecture RTL of XOR3 is
begin
  process(x1, x2, x0) is
  begin
    y <= x1 xor x2 xor x0;
  end process;
end RTL;

-- The FOUR-input XOR gate
library IEEE;
use IEEE.STD_LOGIC_1164.all;
use work.TTU.all;

entity XOR4 is
port(
  x0: in std_logic;
  x1: in std_logic;
  x2: in std_logic;
  x3: in std_logic;
  y: out std_logic);
end XOR4;

architecture RTL of XOR4 is
begin
  process(x1, x2, x3, x0) is
  begin
    y <= x1 xor x2 xor x3 xor x0;
  end process;
end RTL;

-- ------------------------------------
-- NOR GATES

-- The TWO-input NOR gate
library IEEE;
use IEEE.STD_LOGIC_1164.all;
use work.TTU.all;

entity NOR2 is
port(
  x0: in std_logic;
  x1: in std_logic;
  y: out std_logic);
end NOR2;

architecture RTL of NOR2 is
begin
  process(x1, x0) is
  begin
    y <= x1 nor x0;
  end process;
end RTL;

-- The THREE-input NOR gate
library IEEE;
use IEEE.STD_LOGIC_1164.all;
use work.TTU.all;

entity NOR3 is
port(
  x0: in std_logic;
  x1: in std_logic;
  x2: in std_logic;
  y: out std_logic);
end NOR3;

architecture RTL of NOR3 is
begin
  process(x1, x2, x0) is
  begin
    y <= not(x1 or x2 or x0);
  end process;
end RTL;

-- The FOUR-input NOR gate
library IEEE;
use IEEE.STD_LOGIC_1164.all;
use work.TTU.all;

entity NOR4 is
port(
  x0: in std_logic;
  x1: in std_logic;
  x2: in std_logic;
  x3: in std_logic;
  y: out std_logic);
end NOR4;

architecture RTL of NOR4 is
begin
  process(x1, x2, x3, x0) is
  begin
    y <= not(x1 or x2 or x3 or x0);
  end process;
end RTL;

-- ------------------------------------
-- NAND GATES

-- The TWO-input NAND gate
library IEEE;
use IEEE.STD_LOGIC_1164.all;
use work.TTU.all;

entity NAND2 is
port(
  x0: in std_logic;
  x1: in std_logic;
  y: out std_logic);
end NAND2;

architecture RTL of NAND2 is
begin
  process(x1, x0) is
  begin
    y <= x1 nand x0;
  end process;
end RTL;

-- The THREE-input NAND gate
library IEEE;
use IEEE.STD_LOGIC_1164.all;
use work.TTU.all;

entity NAND3 is
port(
  x0: in std_logic;
  x1: in std_logic;
  x2: in std_logic;
  y: out std_logic);
end NAND3;

architecture RTL of NAND3 is
begin
  process(x1, x2, x0) is
  begin
    y <= not(x1 and x2 and x0);
  end process;
end RTL;

-- The FOUR-input NAND gate
library IEEE;
use IEEE.STD_LOGIC_1164.all;
use work.TTU.all;

entity NAND4 is
port(
  x0: in std_logic;
  x1: in std_logic;
  x2: in std_logic;
  x3: in std_logic;
  y: out std_logic);
end NAND4;

architecture RTL of NAND4 is
begin
  process(x1, x2, x3, x0) is
  begin
    y <= not(x1 and x2 and x3 and x0);
  end process;
end RTL;

-- ------------------------------------
-- XNOR GATES

-- The TWO-input XNOR gate
library IEEE;
use IEEE.STD_LOGIC_1164.all;
use work.TTU.all;

entity XNOR2 is
port(
  x0: in std_logic;
  x1: in std_logic;
  y: out std_logic);
end XNOR2;

architecture RTL of XNOR2 is
begin
  process(x1, x0) is
  begin
    y <= x1 xnor x0;
  end process;
end RTL;

-- The THREE-input XNOR gate
library IEEE;
use IEEE.STD_LOGIC_1164.all;
use work.TTU.all;

entity XNOR3 is
port(
  x0: in std_logic;
  x1: in std_logic;
  x2: in std_logic;
  y: out std_logic);
end XNOR3;

architecture RTL of XNOR3 is
begin
  process(x1, x2, x0) is
  begin
    y <= not(x1 xor x2 xor x0);
  end process;
end rtl;

-- The FOUR-input XOR gate
library IEEE;
use IEEE.STD_LOGIC_1164.all;
use work.TTU.all;

entity XNOR4 is
port(
  x0: in std_logic;
  x1: in std_logic;
  x2: in std_logic;
  x3: in std_logic;
  y: out std_logic);
end XNOR4;

architecture RTL of XNOR4 is begin
  process(x1, x2, x3, x0) is
  begin
    y <= not(x0 xor x1 xor x2 xor x3);
  end process;
end RTL;

-- =======================================================
-- === COMBINATIONAL LOGIC BUILDING BLOCKS
-- =======================================================

-- the 3-to-8 decoder
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use work.TTU.all;

entity decoder_3to8 is
	port ( 	sel : in STD_LOGIC_VECTOR (2 downto 0);
			y : out STD_LOGIC_VECTOR (7 downto 0));
end decoder_3to8;

architecture behavioral of decoder_3to8 is
	begin
		with sel select
			y <=	"00000001" when "000",
					"00000010" when "001",
					"00000100" when "010",
					"00001000" when "011",
					"00010000" when "100",
					"00100000" when "101",
					"01000000" when "110",
					"10000000" when "111",
					"00000000" when others;
end behavioral;

-- the two-to-one MUX
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use work.TTU.all;
 
entity mux_2to1 is
	port(	A,B : in STD_LOGIC;
			S: in STD_LOGIC;
			Z: out STD_LOGIC);
end mux_2to1;
 
architecture behavioral of mux_2to1 is
	begin
 
	process (A,B,S) is
		begin
			if (S ='0') then
				Z <= A;
			else
				Z <= B;
			end if;
	end process;
end behavioral;

-- the four-to-one MUX
library IEEE;
use IEEE.STD_LOGIC_1164.all;
use work.TTU.all;

entity mux_4to1 is
 port(A,B,C,D : in STD_LOGIC;
      S0,S1: in STD_LOGIC;
      Z: out STD_LOGIC);
end mux_4to1;
 
architecture behavioral of mux_4to1 is
	begin
		process (A,B,C,D,S0,S1) is
			begin
  				if (S0 ='0' and S1 = '0') then
      				Z <= A;
  				elsif (S0 ='1' and S1 = '0') then
      				Z <= B;
  				elsif (S0 ='0' and S1 = '1') then
      				Z <= C;
  				else
      				Z <= D;
  				end if;
		end process;
end behavioral;

-- =======================================================
-- === SEQUENTIAL GATES
-- =======================================================
-- The SR latch
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use work.TTU.all;

entity SR_LATCH is
    Port ( S : in    STD_LOGIC;
           R : in    STD_LOGIC;
           Q : inout STD_LOGIC;
           Qnot: inout STD_LOGIC); 
end SR_LATCH;

architecture RTL of SR_LATCH is begin
  Q    <= R nor Qnot;
  Qnot <= S nor Q;
end RTL;

-- the SR flip-flop

library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use work.TTU.all;

entity SRFF is port(
  S: in std_logic;
  R: in std_logic;
  CLK: in std_logic;
  RESET: in std_logic;
  Q: out std_logic;
  Qnot: out std_logic);
end SRFF;

architecture RTL of SRFF is begin
  process(S,R,CLK,RESET)
  begin
    if(RESET='1') then		-- async reset
       Q <= '0';
       Qnot <= '0';
    elsif(rising_edge(clk)) then	-- synchronous behavoir
       if( S /= R) then
         Q <= S;
         Qnot <= R;
       elsif (S='1' and R='1') then
         Q <= 'Z';
         Qnot <= 'Z';
       end if;
     end if;
   end process;
end RTL;

-- the D flip-flop

library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use work.TTU.all;

entity DFF is port(
  D: in std_logic;
  CLK: in std_logic;
  RESET: in std_logic;
  Q: out std_logic;
  Qnot: out std_logic);
end DFF;

architecture RTL of DFF is begin
  process(D,CLK,RESET)
  begin
    if(RESET='1') then		-- async reset
       Q <= '0';
       Qnot <= '0';
    elsif(rising_edge(clk)) then	-- synchronous behavoir
       Q <= D;
       Qnot <= not D;
     end if;
   end process;
end RTL;