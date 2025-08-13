library IEEE;
use IEEE.STD_LOGIC_1164.all;

entity bin2seg7 is
 port( inData: in STD_LOGIC_VECTOR(3 downto 0);
		 blanking: in STD_LOGIC;
		 dispHex, dispPoint: in STD_LOGIC;
		 segA, segB, segC, segD: out STD_LOGIC;
		 segE, segF, segG: out STD_LOGIC;
		 segPoint: out STD_LOGIC);
end entity bin2seg7;


architecture behavorial of bin2seg7 is
begin
		-------------------------
		-- Behavior of inData
		-- bit vector
		-------------------------
		Display: process(inData,blanking,dispHex)
		begin
			if(blanking = '0') then
				segA <= '1';
				segB <= '1';
				segC <= '1';
				segD <= '1';
				segE <= '1';
				segF <= '1';
				segG <= '1';
			elsif(dispHex = '0') then
				case (inData) is
					when "0000" => 
						segA <= '0';
						segB <= '0';
						segC <= '0';
						segD <= '0';
						segE <= '0';
						segF <= '0';
						segG <= '1';
					when "0001" => 
						segA <= '1';
						segB <= '0';
						segC <= '0';
						segD <= '1';
						segE <= '1';
						segF <= '1';
						segG <= '1';
					when "0010" => 
						segA <= '0';
						segB <= '0';
						segC <= '1';
						segD <= '0';
						segE <= '0';
						segF <= '1';
						segG <= '0';
					when "0011" => 
						segA <= '0';
						segB <= '0';
						segC <= '0';
						segD <= '0';
						segE <= '1';
						segF <= '1';
						segG <= '0';
					when "0100" => 
						segA <= '1';
						segB <= '0';
						segC <= '0';
						segD <= '1';
						segE <= '1';
						segF <= '0';
						segG <= '0';
					when "0101" => 
						segA <= '0';
						segB <= '1';
						segC <= '0';
						segD <= '0';
						segE <= '1';
						segF <= '0';
						segG <= '0';
					when "0110" => 
						segA <= '0';
						segB <= '1';
						segC <= '0';
						segD <= '0';
						segE <= '0';
						segF <= '0';
						segG <= '0';
					when "0111" => 
						segA <= '0';
						segB <= '0';
						segC <= '0';
						segD <= '1';
						segE <= '1';
						segF <= '1';
						segG <= '1';
					when "1000" => 
						segA <= '0';
						segB <= '0';
						segC <= '0';
						segD <= '0';
						segE <= '0';
						segF <= '0';
						segG <= '0';
					when "1001" => 
						segA <= '0';
						segB <= '0';
						segC <= '0';
						segD <= '1';
						segE <= '1';
						segF <= '0';
						segG <= '0';
					when others =>
						segA <= '1';
						segB <= '1';
						segC <= '1';
						segD <= '1';
						segE <= '1';
						segF <= '1';
						segG <= '1';
				end case;
			else
				case (inData) is
					when "0000" => 
						segA <= '0';
						segB <= '0';
						segC <= '0';
						segD <= '0';
						segE <= '0';
						segF <= '0';
						segG <= '1';
					when "0001" => 
						segA <= '1';
						segB <= '0';
						segC <= '0';
						segD <= '1';
						segE <= '1';
						segF <= '1';
						segG <= '1';
					when "0010" => 
						segA <= '0';
						segB <= '0';
						segC <= '1';
						segD <= '0';
						segE <= '0';
						segF <= '1';
						segG <= '0';
					when "0011" => 
						segA <= '0';
						segB <= '0';
						segC <= '0';
						segD <= '0';
						segE <= '1';
						segF <= '1';
						segG <= '0';
					when "0100" => 
						segA <= '1';
						segB <= '0';
						segC <= '0';
						segD <= '1';
						segE <= '1';
						segF <= '0';
						segG <= '0';
					when "0101" => 
						segA <= '0';
						segB <= '1';
						segC <= '0';
						segD <= '0';
						segE <= '1';
						segF <= '0';
						segG <= '0';
					when "0110" => 
						segA <= '0';
						segB <= '1';
						segC <= '0';
						segD <= '0';
						segE <= '0';
						segF <= '0';
						segG <= '0';
					when "0111" => 
						segA <= '0';
						segB <= '0';
						segC <= '0';
						segD <= '1';
						segE <= '1';
						segF <= '1';
						segG <= '1';
					when "1000" => 
						segA <= '0';
						segB <= '0';
						segC <= '0';
						segD <= '0';
						segE <= '0';
						segF <= '0';
						segG <= '0';
					when "1001" => 
						segA <= '0';
						segB <= '0';
						segC <= '0';
						segD <= '1';
						segE <= '1';
						segF <= '0';
						segG <= '0';
					when "1010" => 
						segA <= '0';
						segB <= '0';
						segC <= '0';
						segD <= '1';
						segE <= '0';
						segF <= '0';
						segG <= '0';
					when "1011" => 
						segA <= '1';
						segB <= '1';
						segC <= '0';
						segD <= '0';
						segE <= '0';
						segF <= '0';
						segG <= '0';
					when "1100" => 
						segA <= '0';
						segB <= '1';
						segC <= '1';
						segD <= '0';
						segE <= '0';
						segF <= '0';
						segG <= '1';
					when "1101" => 
						segA <= '1';
						segB <= '0';
						segC <= '0';
						segD <= '0';
						segE <= '0';
						segF <= '1';
						segG <= '0';
					when "1110" => 
						segA <= '0';
						segB <= '1';
						segC <= '1';
						segD <= '0';
						segE <= '0';
						segF <= '0';
						segG <= '0';
					when "1111" => 
						segA <= '0';
						segB <= '1';
						segC <= '1';
						segD <= '1';
						segE <= '0';
						segF <= '0';
						segG <= '0';
					when others =>
						segA <= '1';
						segB <= '1';
						segC <= '1';
						segD <= '1';
						segE <= '1';
						segF <= '1';
						segG <= '1';
				end case;
			end if;
		end process;
		Decimal: process(blanking, dispPoint)
		begin
			if(blanking = '0') then
				segPoint <= '1';
			elsif(dispPoint = '1') then
				segPoint <= '0';
			else
				segPoint <= '1';
			end if;
		end process;
end architecture behavorial;