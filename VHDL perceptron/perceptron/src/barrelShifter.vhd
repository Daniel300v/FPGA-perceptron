library IEEE;
use IEEE.std_logic_1164.all;

entity barrelShifter is
    port(barrelIn : in std_logic_vector(7 downto 0);
         totalShift : in std_logic_vector(2 downto 0);
         barrelOut : out std_logic_vector(7 downto 0));
end barrelShifter;

architecture barrelShifterLogic of barrelShifter is
    component oneBitLeftShift
    port(inA : in std_logic_vector(7 downto 0);
         shift : in std_logic;
         shifted : out std_logic_vector(7 downto 0));
    end component;
    
    component twoBitLeftShift
    port(inA : in std_logic_vector(7 downto 0);
         shift : in std_logic;
         shifted : out std_logic_vector(7 downto 0));
    end component;

    component fourBitLeftShift
    port(inA : in std_logic_vector(7 downto 0);
         shift : in std_logic;
         shifted : out std_logic_vector(7 downto 0));
    end component;

    signal oneShift: std_logic_vector(7 downto 0);
    signal twoShift: std_logic_vector(7 downto 0);
    

    begin

    start: oneBitLeftShift
    port map (inA => barrelIn, 
              shift => totalShift(0),
              shifted => oneShift);

    two: twoBitLeftShift
    port map (inA => oneShift, 
              shift => totalShift(1),
              shifted => twoShift);

    four: fourBitLeftShift
    port map (inA => twoShift, 
              shift => totalShift(2),
              shifted => barrelOut);
        

end barrelShifterLogic;