-- File Name: Register_mux.vhd
-- Author: Tate Finley
-- Purpose: multiplexer for inside the register unit.

library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.NUMERIC_STD.ALL;
use work.RegisterPackage.ALL;

entity Register_mux is
	port(	reg_num_and_data : in RegisterArrayType;
			S: in STD_LOGIC_VECTOR(4 downto 0);
			Z: out STD_LOGIC_VECTOR(31 downto 0));	
end Register_mux;
 
architecture behavioral of Register_mux is
	begin
	process (S,reg_num_and_data) is
		begin
			Z <= reg_num_and_data(to_integer(unsigned(S)));
	end process;
end behavioral;