library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

library work;
use work.TTU.all;

entity hw5p3 is 
	port( Clock, SetState: in std_logic;
			o_LFSR : out std_logic_vector(4 downto 0));
end hw5p3;

architecture RTL of hw5p3 is 
	constant Prime1 : integer := 3; --LFSR 1
	constant Prime2 : integer := 5; --LFSR 2
	constant Prime3 : integer := 7; --LFSR 3
	constant Prime4 : integer := 13; --LFSR 4
	constant Prime5 : integer := 17; --LFSR 5
	
	
	component my_LFSR is 
		generic (Num_Bits : integer);
		port( CLK, Enable, Set: in std_logic;
			Set_vec : in std_logic_vector(Num_Bits-1 downto 0);
			o_LFSR_vec : buffer std_logic_vector(Num_Bits-1 downto 0));
			--leftmost_LFSRbit : out std_logic);
	end component;
	
	signal vecValue1 : std_logic_vector(Prime1-1 downto 0);
	signal vecValue2 : std_logic_vector(Prime2-1 downto 0);
	signal vecValue3 : std_logic_vector(Prime3-1 downto 0);
	signal vecValue4 : std_logic_vector(Prime4-1 downto 0);
	signal vecValue5 : std_logic_vector(Prime5-1 downto 0);
	
	
begin
	
	
	U0: my_LFSR generic map(Num_Bits=>Prime1)
		port map(CLK=>clock,
					Enable=>'1',
					Set=>SetState,
					Set_vec=> (others=>'0'),
					o_LFSR_vec=>vecValue1);
	U1: my_LFSR generic map(Num_Bits=>Prime2)
		port map(CLK=>clock,
					Enable=>'1',
					Set=>SetState,
					Set_vec=> (others=>'0'),
					o_LFSR_vec=>vecValue2);
	U2: my_LFSR generic map(Num_Bits=>Prime3)
		port map(CLK=>clock,
					Enable=>'1',
					Set=>SetState,
					Set_vec=>(others=>'0'),
					o_LFSR_vec=>vecValue3);
	U3: my_LFSR generic map(Num_Bits=>Prime4)
		port map(CLK=>clock,
					Enable=>'1',
					Set=>SetState,
					Set_vec=>(others=>'0'),
					o_LFSR_vec=>vecValue4);
	U4: my_LFSR generic map(Num_Bits=>Prime5)
		port map(CLK=>clock,
					Enable=>'1',
					Set=>SetState,
					Set_vec=>(others=>'0'),
					o_LFSR_vec=>vecValue5);
	
	o_LFSR(0) <= vecValue1(0);
	o_LFSR(1) <= vecValue2(0);
	o_LFSR(2) <= vecValue3(0);
	o_LFSR(3) <= vecValue4(0);
	o_LFSR(4) <= vecValue5(0);
  
end RTL;
