-- File Name: ReadUnit.vhd
-- Author: Tate Finley
-- Purpose: read only functionality for the registers.

library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use work.RegisterPackage.ALL;

entity ReadUnit is
    Port (reg_read_1 : in STD_LOGIC_VECTOR(4 downto 0);
			reg_read_2 : in STD_LOGIC_VECTOR(4 downto 0);
			all_regs_with_data : in RegisterArrayType;
			data_reg1 : out STD_LOGIC_VECTOR(31 downto 0);
			data_reg2 : out STD_LOGIC_VECTOR(31 downto 0));
end ReadUnit;

architecture Structural of ReadUnit is

    component Register_mux
        port(	reg_num_and_data : in RegisterArrayType;
			S: in STD_LOGIC_VECTOR(4 downto 0);
			Z: out STD_LOGIC_VECTOR(31 downto 0));	
	 end component;

begin
    -- Multiplexer for Read Data Outputs
    DUT1: Register_mux port map (all_regs_with_data, reg_read_1, data_reg1);

    DUT2: Register_mux port map (all_regs_with_data, reg_read_2, data_reg2);

end Structural;
