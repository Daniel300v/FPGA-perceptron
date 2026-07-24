library IEEE;
use IEEE.std_logic_1164.all;

entity fullAdder is
    port(A : in std_logic; 
         B : in std_logic;
         C : in std_logic;
         SUM : out std_logic;
         CARRY : out std_logic);
end fullAdder;

architecture fullAdderLogic of fullAdder is
    signal axorb : std_logic;
    signal aandb : std_logic;
    signal candaxorb : std_logic;

    begin
        axorb <= A xor B;
        aandb <= A and B;
        SUM <= axorb xor C;
        candaxorb <= C and axorb;
        CARRY <= aandb or candaxorb;
        
end fullAdderLogic;