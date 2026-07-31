library IEEE;
use IEEE.std_logic_1164.all;

entity comparitor is
    port(perceved : in std_logic_vector(7 downto 0);
         static : in std_logic_vector(7 downto 0);
         activation : out std_logic);
end comparitor;

architecture comparitorLogic of comparitor is
    signal equivelance : std_logic;
    signal greater : std_logic;
    signal equivelanceVector: std_logic_vector(7 downto 0);

    begin 
        -- this covers equivelance 
        equivelanceVector(0) <= perceved(0) xnor static(0);
        equivelanceVector(1) <= perceved(1) xnor static(1);
        equivelanceVector(2) <= perceved(2) xnor static(2);
        equivelanceVector(3) <= perceved(3) xnor static(3);
        equivelanceVector(4) <= perceved(4) xnor static(4);
        equivelanceVector(5) <= perceved(5) xnor static(5);
        equivelanceVector(6) <= perceved(6) xnor static(6);
        equivelanceVector(7) <= perceved(7) xnor static(7);
        equivelance <= (equivelanceVector(0) and equivelanceVector(1) and equivelanceVector(2) and equivelanceVector(3) and
                        equivelanceVector(4) and equivelanceVector(5) and equivelanceVector(6) and equivelanceVector(7));

        --this covers greater than

        greater <= '1' when perceved > static else '0';

        activation <= equivelance or greater;

end comparitorLogic;