library IEEE;
use IEEE.std_logic_1164.all;

entity halfAdder is
    port(A : in std_logic; 
         B : in std_logic;
         SUM : out std_logic;
         CARRY : out std_logic);
end halfAdder;

architecture halfAdderLogic of halfAdder is

    begin
        CARRY <= A and B;
        SUM <= A xor B;
end halfAdderLogic;