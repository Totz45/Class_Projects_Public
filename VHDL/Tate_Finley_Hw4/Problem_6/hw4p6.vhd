library IEEE;
use IEEE.STD_LOGIC_1164.all;

entity hw4p6 is
 port( SW: in STD_LOGIC_VECTOR(3 downto 0);
       SW4: in STD_LOGIC;
		 Switch: in STD_LOGIC_VECTOR(7 downto 5);
		 KEY: in STD_LOGIC_VECTOR(1 downto 0);
		 HEX0,HEX1,HEX2,HEX3,HEX4,HEX5: out STD_LOGIC_VECTOR(7 downto 0));
end entity hw4p6;

architecture behavoral of hw4p6 is
	
	signal segment : STD_LOGIC_VECTOR(7 downto 0);

	component bin2seg7 is
		port( inData: in STD_LOGIC_VECTOR(3 downto 0);
				blanking: in STD_LOGIC;
				dispHex, dispPoint: in STD_LOGIC;
				segA, segB, segC, segD: out STD_LOGIC;
				segE, segF, segG: out STD_LOGIC;
				segPoint: out STD_LOGIC);
	end component bin2seg7;
	
	begin
	
		DUT0: bin2seg7 port map (inData=>SW,blanking=>KEY(0),dispHex=>KEY(1),dispPoint=>SW4,segA=>segment(0),segB=>segment(1),segC=>segment(2),segD=>segment(3),segE=>segment(4),segF=>segment(5),segG=>segment(6),segPoint=>segment(7)); 
	
		DISPLAY: process (Switch,segment)
		begin
			case(Switch) is
				when "000" =>
					HEX0(0) <= segment(0);
					HEX0(1) <= segment(1);
					HEX0(2) <= segment(2);
					HEX0(3) <= segment(3);
					HEX0(4) <= segment(4);
					HEX0(5) <= segment(5);
					HEX0(6) <= segment(6);
					HEX0(7) <= segment(7);
					
					HEX1(0) <= '1';
					HEX1(1) <= '1';
					HEX1(2) <= '1';
					HEX1(3) <= '1';
					HEX1(4) <= '1';
					HEX1(5) <= '1';
					HEX1(6) <= '1';
					HEX1(7) <= '1';
					
					HEX2(0) <= '1';
					HEX2(1) <= '1';
					HEX2(2) <= '1';
					HEX2(3) <= '1';
					HEX2(4) <= '1';
					HEX2(5) <= '1';
					HEX2(6) <= '1';
					HEX2(7) <= '1';
					
					HEX3(0) <= '1';
					HEX3(1) <= '1';
					HEX3(2) <= '1';
					HEX3(3) <= '1';
					HEX3(4) <= '1';
					HEX3(5) <= '1';
					HEX3(6) <= '1';
					HEX3(7) <= '1';
					
					HEX4(0) <= '1';
					HEX4(1) <= '1';
					HEX4(2) <= '1';
					HEX4(3) <= '1';
					HEX4(4) <= '1';
					HEX4(5) <= '1';
					HEX4(6) <= '1';
					HEX4(7) <= '1';
					
					HEX5(0) <= '1';
					HEX5(1) <= '1';
					HEX5(2) <= '1';
					HEX5(3) <= '1';
					HEX5(4) <= '1';
					HEX5(5) <= '1';
					HEX5(6) <= '1';
					HEX5(7) <= '1';
				when "001" =>
					HEX0(0) <= '1';
					HEX0(1) <= '1';
					HEX0(2) <= '1';
					HEX0(3) <= '1';
					HEX0(4) <= '1';
					HEX0(5) <= '1';
					HEX0(6) <= '1';
					HEX0(7) <= '1';
					
					HEX1(0) <= segment(0);
					HEX1(1) <= segment(1);
					HEX1(2) <= segment(2);
					HEX1(3) <= segment(3);
					HEX1(4) <= segment(4);
					HEX1(5) <= segment(5);
					HEX1(6) <= segment(6);
					HEX1(7) <= segment(7);
					
					HEX2(0) <= '1';
					HEX2(1) <= '1';
					HEX2(2) <= '1';
					HEX2(3) <= '1';
					HEX2(4) <= '1';
					HEX2(5) <= '1';
					HEX2(6) <= '1';
					HEX2(7) <= '1';
					
					HEX3(0) <= '1';
					HEX3(1) <= '1';
					HEX3(2) <= '1';
					HEX3(3) <= '1';
					HEX3(4) <= '1';
					HEX3(5) <= '1';
					HEX3(6) <= '1';
					HEX3(7) <= '1';
					
					HEX4(0) <= '1';
					HEX4(1) <= '1';
					HEX4(2) <= '1';
					HEX4(3) <= '1';
					HEX4(4) <= '1';
					HEX4(5) <= '1';
					HEX4(6) <= '1';
					HEX4(7) <= '1';
					
					HEX5(0) <= '1';
					HEX5(1) <= '1';
					HEX5(2) <= '1';
					HEX5(3) <= '1';
					HEX5(4) <= '1';
					HEX5(5) <= '1';
					HEX5(6) <= '1';
					HEX5(7) <= '1';
				when "010" =>
					HEX0(0) <= '1';
					HEX0(1) <= '1';
					HEX0(2) <= '1';
					HEX0(3) <= '1';
					HEX0(4) <= '1';
					HEX0(5) <= '1';
					HEX0(6) <= '1';
					HEX0(7) <= '1';
					
					HEX1(0) <= '1';
					HEX1(1) <= '1';
					HEX1(2) <= '1';
					HEX1(3) <= '1';
					HEX1(4) <= '1';
					HEX1(5) <= '1';
					HEX1(6) <= '1';
					HEX1(7) <= '1';
					
					HEX2(0) <= segment(0);
					HEX2(1) <= segment(1);
					HEX2(2) <= segment(2);
					HEX2(3) <= segment(3);
					HEX2(4) <= segment(4);
					HEX2(5) <= segment(5);
					HEX2(6) <= segment(6);
					HEX2(7) <= segment(7);
					
					HEX3(0) <= '1';
					HEX3(1) <= '1';
					HEX3(2) <= '1';
					HEX3(3) <= '1';
					HEX3(4) <= '1';
					HEX3(5) <= '1';
					HEX3(6) <= '1';
					HEX3(7) <= '1';
					
					HEX4(0) <= '1';
					HEX4(1) <= '1';
					HEX4(2) <= '1';
					HEX4(3) <= '1';
					HEX4(4) <= '1';
					HEX4(5) <= '1';
					HEX4(6) <= '1';
					HEX4(7) <= '1';
					
					HEX5(0) <= '1';
					HEX5(1) <= '1';
					HEX5(2) <= '1';
					HEX5(3) <= '1';
					HEX5(4) <= '1';
					HEX5(5) <= '1';
					HEX5(6) <= '1';
					HEX5(7) <= '1';
				when "011" =>
					HEX0(0) <= '1';
					HEX0(1) <= '1';
					HEX0(2) <= '1';
					HEX0(3) <= '1';
					HEX0(4) <= '1';
					HEX0(5) <= '1';
					HEX0(6) <= '1';
					HEX0(7) <= '1';
					
					HEX1(0) <= '1';
					HEX1(1) <= '1';
					HEX1(2) <= '1';
					HEX1(3) <= '1';
					HEX1(4) <= '1';
					HEX1(5) <= '1';
					HEX1(6) <= '1';
					HEX1(7) <= '1';
					
					HEX2(0) <= '1';
					HEX2(1) <= '1';
					HEX2(2) <= '1';
					HEX2(3) <= '1';
					HEX2(4) <= '1';
					HEX2(5) <= '1';
					HEX2(6) <= '1';
					HEX2(7) <= '1';
					
					HEX3(0) <= segment(0);
					HEX3(1) <= segment(1);
					HEX3(2) <= segment(2);
					HEX3(3) <= segment(3);
					HEX3(4) <= segment(4);
					HEX3(5) <= segment(5);
					HEX3(6) <= segment(6);
					HEX3(7) <= segment(7);
					
					HEX4(0) <= '1';
					HEX4(1) <= '1';
					HEX4(2) <= '1';
					HEX4(3) <= '1';
					HEX4(4) <= '1';
					HEX4(5) <= '1';
					HEX4(6) <= '1';
					HEX4(7) <= '1';
					
					HEX5(0) <= '1';
					HEX5(1) <= '1';
					HEX5(2) <= '1';
					HEX5(3) <= '1';
					HEX5(4) <= '1';
					HEX5(5) <= '1';
					HEX5(6) <= '1';
					HEX5(7) <= '1';
				when "100" =>
					HEX0(0) <= '1';
					HEX0(1) <= '1';
					HEX0(2) <= '1';
					HEX0(3) <= '1';
					HEX0(4) <= '1';
					HEX0(5) <= '1';
					HEX0(6) <= '1';
					HEX0(7) <= '1';
					
					HEX1(0) <= '1';
					HEX1(1) <= '1';
					HEX1(2) <= '1';
					HEX1(3) <= '1';
					HEX1(4) <= '1';
					HEX1(5) <= '1';
					HEX1(6) <= '1';
					HEX1(7) <= '1';
					
					HEX2(0) <= '1';
					HEX2(1) <= '1';
					HEX2(2) <= '1';
					HEX2(3) <= '1';
					HEX2(4) <= '1';
					HEX2(5) <= '1';
					HEX2(6) <= '1';
					HEX2(7) <= '1';
					
					HEX3(0) <= '1';
					HEX3(1) <= '1';
					HEX3(2) <= '1';
					HEX3(3) <= '1';
					HEX3(4) <= '1';
					HEX3(5) <= '1';
					HEX3(6) <= '1';
					HEX3(7) <= '1';
					
					HEX4(0) <= segment(0);
					HEX4(1) <= segment(1);
					HEX4(2) <= segment(2);
					HEX4(3) <= segment(3);
					HEX4(4) <= segment(4);
					HEX4(5) <= segment(5);
					HEX4(6) <= segment(6);
					HEX4(7) <= segment(7);
					
					HEX5(0) <= '1';
					HEX5(1) <= '1';
					HEX5(2) <= '1';
					HEX5(3) <= '1';
					HEX5(4) <= '1';
					HEX5(5) <= '1';
					HEX5(6) <= '1';
					HEX5(7) <= '1';
				when "101" =>
					HEX0(0) <= '1';
					HEX0(1) <= '1';
					HEX0(2) <= '1';
					HEX0(3) <= '1';
					HEX0(4) <= '1';
					HEX0(5) <= '1';
					HEX0(6) <= '1';
					HEX0(7) <= '1';
					
					HEX1(0) <= '1';
					HEX1(1) <= '1';
					HEX1(2) <= '1';
					HEX1(3) <= '1';
					HEX1(4) <= '1';
					HEX1(5) <= '1';
					HEX1(6) <= '1';
					HEX1(7) <= '1';
					
					HEX2(0) <= '1';
					HEX2(1) <= '1';
					HEX2(2) <= '1';
					HEX2(3) <= '1';
					HEX2(4) <= '1';
					HEX2(5) <= '1';
					HEX2(6) <= '1';
					HEX2(7) <= '1';
					
					HEX3(0) <= '1';
					HEX3(1) <= '1';
					HEX3(2) <= '1';
					HEX3(3) <= '1';
					HEX3(4) <= '1';
					HEX3(5) <= '1';
					HEX3(6) <= '1';
					HEX3(7) <= '1';
					
					HEX4(0) <= '1';
					HEX4(1) <= '1';
					HEX4(2) <= '1';
					HEX4(3) <= '1';
					HEX4(4) <= '1';
					HEX4(5) <= '1';
					HEX4(6) <= '1';
					HEX4(7) <= '1';
					
					HEX5(0) <= segment(0);
					HEX5(1) <= segment(1);
					HEX5(2) <= segment(2);
					HEX5(3) <= segment(3);
					HEX5(4) <= segment(4);
					HEX5(5) <= segment(5);
					HEX5(6) <= segment(6);
					HEX5(7) <= segment(7);
				when "110" =>
					HEX0(0) <= '1';
					HEX0(1) <= '1';
					HEX0(2) <= '1';
					HEX0(3) <= '1';
					HEX0(4) <= '1';
					HEX0(5) <= '1';
					HEX0(6) <= '1';
					HEX0(7) <= '1';
					
					HEX1(0) <= segment(0);
					HEX1(1) <= segment(1);
					HEX1(2) <= segment(2);
					HEX1(3) <= segment(3);
					HEX1(4) <= segment(4);
					HEX1(5) <= segment(5);
					HEX1(6) <= segment(6);
					HEX1(7) <= segment(7);
					
					HEX2(0) <= '1';
					HEX2(1) <= '1';
					HEX2(2) <= '1';
					HEX2(3) <= '1';
					HEX2(4) <= '1';
					HEX2(5) <= '1';
					HEX2(6) <= '1';
					HEX2(7) <= '1';
					
					HEX3(0) <= segment(0);
					HEX3(1) <= segment(1);
					HEX3(2) <= segment(2);
					HEX3(3) <= segment(3);
					HEX3(4) <= segment(4);
					HEX3(5) <= segment(5);
					HEX3(6) <= segment(6);
					HEX3(7) <= segment(7);
					
					HEX4(0) <= '1';
					HEX4(1) <= '1';
					HEX4(2) <= '1';
					HEX4(3) <= '1';
					HEX4(4) <= '1';
					HEX4(5) <= '1';
					HEX4(6) <= '1';
					HEX4(7) <= '1';
					
					HEX5(0) <= segment(0);
					HEX5(1) <= segment(1);
					HEX5(2) <= segment(2);
					HEX5(3) <= segment(3);
					HEX5(4) <= segment(4);
					HEX5(5) <= segment(5);
					HEX5(6) <= segment(6);
					HEX5(7) <= segment(7);
				when "111" =>
					HEX0(0) <= segment(0);
					HEX0(1) <= segment(1);
					HEX0(2) <= segment(2);
					HEX0(3) <= segment(3);
					HEX0(4) <= segment(4);
					HEX0(5) <= segment(5);
					HEX0(6) <= segment(6);
					HEX0(7) <= segment(7);
					
					HEX1(0) <= segment(0);
					HEX1(1) <= segment(1);
					HEX1(2) <= segment(2);
					HEX1(3) <= segment(3);
					HEX1(4) <= segment(4);
					HEX1(5) <= segment(5);
					HEX1(6) <= segment(6);
					HEX1(7) <= segment(7);
					
					HEX2(0) <= segment(0);
					HEX2(1) <= segment(1);
					HEX2(2) <= segment(2);
					HEX2(3) <= segment(3);
					HEX2(4) <= segment(4);
					HEX2(5) <= segment(5);
					HEX2(6) <= segment(6);
					HEX2(7) <= segment(7);
					
					HEX3(0) <= segment(0);
					HEX3(1) <= segment(1);
					HEX3(2) <= segment(2);
					HEX3(3) <= segment(3);
					HEX3(4) <= segment(4);
					HEX3(5) <= segment(5);
					HEX3(6) <= segment(6);
					HEX3(7) <= segment(7);
					
					HEX4(0) <= segment(0);
					HEX4(1) <= segment(1);
					HEX4(2) <= segment(2);
					HEX4(3) <= segment(3);
					HEX4(4) <= segment(4);
					HEX4(5) <= segment(5);
					HEX4(6) <= segment(6);
					HEX4(7) <= segment(7);
					
					HEX5(0) <= segment(0);
					HEX5(1) <= segment(1);
					HEX5(2) <= segment(2);
					HEX5(3) <= segment(3);
					HEX5(4) <= segment(4);
					HEX5(5) <= segment(5);
					HEX5(6) <= segment(6);
					HEX5(7) <= segment(7);
				when others => 
					HEX0(0) <= '1';
					HEX0(1) <= '1';
					HEX0(2) <= '1';
					HEX0(3) <= '1';
					HEX0(4) <= '1';
					HEX0(5) <= '1';
					HEX0(6) <= '1';
					HEX0(7) <= '1';
					
					HEX1(0) <= '1';
					HEX1(1) <= '1';
					HEX1(2) <= '1';
					HEX1(3) <= '1';
					HEX1(4) <= '1';
					HEX1(5) <= '1';
					HEX1(6) <= '1';
					HEX1(7) <= '1';
					
					HEX2(0) <= '1';
					HEX2(1) <= '1';
					HEX2(2) <= '1';
					HEX2(3) <= '1';
					HEX2(4) <= '1';
					HEX2(5) <= '1';
					HEX2(6) <= '1';
					HEX2(7) <= '1';
					
					HEX3(0) <= '1';
					HEX3(1) <= '1';
					HEX3(2) <= '1';
					HEX3(3) <= '1';
					HEX3(4) <= '1';
					HEX3(5) <= '1';
					HEX3(6) <= '1';
					HEX3(7) <= '1';
					
					HEX4(0) <= '1';
					HEX4(1) <= '1';
					HEX4(2) <= '1';
					HEX4(3) <= '1';
					HEX4(4) <= '1';
					HEX4(5) <= '1';
					HEX4(6) <= '1';
					HEX4(7) <= '1';
					
					HEX5(0) <= '1';
					HEX5(1) <= '1';
					HEX5(2) <= '1';
					HEX5(3) <= '1';
					HEX5(4) <= '1';
					HEX5(5) <= '1';
					HEX5(6) <= '1';
					HEX5(7) <= '1';
			end case;
		end process;
	

end architecture behavoral;