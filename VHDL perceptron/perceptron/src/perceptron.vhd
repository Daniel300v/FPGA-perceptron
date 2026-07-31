library IEEE;
use IEEE.std_logic_1164.all;

entity perceptron is
    port(source : in std_logic_vector(7 downto 0);
         sink : out std_logic_vector(7 downto 0));
end perceptron;

architecture perceptronLogic of perceptron is 

    component barrelShifter
    port(barrelIn : in std_logic_vector(7 downto 0);
         totalShift : in std_logic_vector(2 downto 0);
         barrelOut : out std_logic_vector(7 downto 0));
    end component;

    component eightBitAdder
    port(inA : in std_logic_vector(7 downto 0);
         inB : in std_logic_vector(7 downto 0);
         SUM : out std_logic_vector(7 downto 0));
    end component;

    signal carry : std_logic_vector (7 downto 0);
    

    begin
        start: barrelShifter
        port map (barrelIn => source,
             totalShift => "010",
             barrelOut => carry);

        offset: eightBitAdder
        port map (inA => carry,
             inB => "00000101",
             SUM => sink);

end perceptronLogic;