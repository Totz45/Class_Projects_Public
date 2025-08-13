library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity Control_unit is 
	port( opcode:					IN STD_LOGIC_VECTOR(5 downto 0);
			clk :  					IN STD_LOGIC;
			EX: 				OUT STD_LOGIC_VECTOR(3 downto 0);
			MEM: 				OUT STD_LOGIC_VECTOR(2 downto 0);
			WB:			OUT STD_LOGIC_VECTOR(1 downto 0));
end entity Control_unit;

library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

architecture Behavioral of Control_unit is
signal EX_sig : STD_LOGIC_VECTOR(3 downto 0);
signal MEM_sig : STD_LOGIC_VECTOR(2 downto 0);
signal WB_sig : STD_LOGIC_VECTOR(1 downto 0);

begin
    process(opcode)
    begin
        -- Default signal settings
		  EX_sig <= "0000";
		  MEM_sig <= "000";
		  WB_sig <= "00";
        
        case opcode is
            when "000000" => -- R-type instructions
					 EX_sig <= "1100";
					 MEM_sig <= "000";
					 WB_sig <= "10";
                
            when "100011" => -- lw
					 EX_sig <= "0001";
					 MEM_sig <= "010";
					 WB_sig <= "11";
                
            when "101011" => -- sw
					 EX_sig <= "0001";
					 MEM_sig <= "001";
					 WB_sig <= "00";
                
            when "000100" => -- beq
                EX_sig <= "0010";
					 MEM_sig <= "100";
					 WB_sig <= "00";
					 
            when "001000" => -- addi
                EX_sig <= "0001";
					 MEM_sig <= "000";
					 WB_sig <= "10";
					 
            when others =>
                null;
        end case;
    end process;
	 
	 EX <= EX_sig;
	 MEM <= MEM_sig;
	 WB <= WB_sig;
	 
end Behavioral;