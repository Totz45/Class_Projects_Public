-- develop shift register
-- develop state graph
Library ieee;
use ieee.std_logic_1164.all;

entity shift_register is
	Generic (n : INTEGER);
	Port( din : IN STD_LOGIC_VECTOR(n-1 downto 0);
	      en, clk, arst : IN STD_LOGIC;
			dout : OUT STD_LOGIC_VECTOR(n-1 downto 0));
end entity shift_register;


architecture rtl of shift_register is
signal reg, nxt : std_logic_vector(n-1 downto 0);
begin
	
dff_shifter: process(arst, clk) begin
	if (arst = '1') then
		reg <= (others => '0');
	elsif (rising_edge(clk)) then
		if (en = '1') then
			reg <= nxt;
		end if;
	end if;
end process;

cmb_shifter: process(reg, din) begin
	nxt <= reg(n-2 downto 0) & din;
end process;
dout <= reg;
end rtl;