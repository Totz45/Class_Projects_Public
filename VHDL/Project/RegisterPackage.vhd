-- File Name: RegisterPackage.vhd
-- Author: Tate Finley
-- Purpose: Import number of registers with data to lower level systems.

library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

package RegisterPackage is
    type RegisterArrayType is array (0 to 31) of STD_LOGIC_VECTOR(31 downto 0);
end RegisterPackage;

package body RegisterPackage is
end RegisterPackage;
