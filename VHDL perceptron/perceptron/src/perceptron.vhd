library IEEE;
use IEEE.std_logic_1164.all;

entity perceptron is
    port(source : in std_logic_vector(7 downto 0);
         selector  : in std_logic_vector (1 downto 0);
         sink : out std_logic);
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

    component comparitor
    port(perceved : in std_logic_vector(7 downto 0);
         static : in std_logic_vector(7 downto 0);
         activation : out std_logic);
    end component;

    signal carry : std_logic_vector (7 downto 0);
    signal neuronProduct : std_logic_vector (7 downto 0);
    
    signal weight : std_logic_vector(2 downto 0) := "010";
    signal bias : std_logic_vector(7 downto 0) := "00000101";
    signal threshold : std_logic_vector(7 downto 0) := "00010000";
    signal drain : std_logic_vector (7 downto 0);
    begin
              
        start: barrelShifter
        port map (barrelIn => source,
             totalShift => "010",
             barrelOut => carry);

        offset: eightBitAdder
        port map (inA => carry,
             inB => "00000101",
             SUM => neuronProduct);

        --neuronProduct <= "00000001";

        comp: comparitor
        port map (perceved => neuronProduct,
                  static => "00010000",
                  activation => sink);
    
    process(selector, source)
    begin
        case selector is
            when "00" =>
                null;
            when "01" =>
                weight <= source(2 downto 0); 
            when "10" =>
                bias <= source;
            when "11" =>
                threshold <= source;
            when others =>
                null;
        end case;
    end process;

end perceptronLogic;