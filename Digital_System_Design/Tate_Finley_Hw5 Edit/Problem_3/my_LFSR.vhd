library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

library work;
use work.TTU.all;

entity my_LFSR is 
	generic (Num_Bits : integer);
	port( CLK, Enable, Set: in std_logic;
			Set_vec : in std_logic_vector(Num_Bits-1 downto 0);
			o_LFSR_vec : buffer std_logic_vector(Num_Bits-1 downto 0));
			--leftmost_LFSRbit : out std_logic);
end my_LFSR;

architecture RTL of my_LFSR is 
	signal next_LFSR : std_logic_vector(Num_Bits downto 1) := (others => '0');
	signal my_XNOR : std_logic;
	
begin
	
	p_LFSR: process(CLK, Set, Set_vec) is
	begin
		if Set = '1' then
			next_LFSR <= Set_vec;
		elsif rising_edge(CLK) then
			if Enable = '1' then
					next_LFSR <= next_LFSR(next_LFSR'left-1 downto 1) & my_XNOR;
			end if;
		end if;
	end process p_LFSR;
	
	Prime_LFSR_1 : if Num_Bits = 3 generate
		my_XNOR <= next_LFSR(3) XNOR next_LFSR(2);
	end generate Prime_LFSR_1;
	
	Prime_LFSR_2 : if Num_Bits = 5 generate
		my_XNOR <= next_LFSR(5) XNOR next_LFSR(3);
	end generate Prime_LFSR_2;
	
	Prime_LFSR_3 : if Num_Bits = 7 generate
		my_XNOR <= next_LFSR(7) XNOR next_LFSR(6);
	end generate Prime_LFSR_3;
	
	--despite 11 being prime 2^11-1 = not a prime number
	
	Prime_LFSR_4 : if Num_Bits = 13 generate
		my_XNOR <= next_LFSR(13) XNOR next_LFSR(4) XNOR next_LFSR(3) XNOR next_LFSR(1);
	end generate Prime_LFSR_4;
	
	Prime_LFSR_5 : if Num_Bits = 17 generate
		my_XNOR <= next_LFSR(17) XNOR next_LFSR(14);
	end generate Prime_LFSR_5;
	
	o_LFSR_vec <= next_LFSR(next_LFSR'left downto 1);
	--leftmost_LFSRbit <= o_LFSR_vec(o_LFSR_vec'left);
  
end RTL;