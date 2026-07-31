import cocotb
from cocotb.triggers import Timer


@cocotb.test()
async def test1(dut):
    """(9 * 4) + 5 is greater than 16"""

    dut.source.value = "00001010"


    await Timer(1, unit="ns")

    print (dut.carry.value)
    print (dut.neuronProduct.value)
    print (dut.sink.value)
    assert dut.sink.value == 1



