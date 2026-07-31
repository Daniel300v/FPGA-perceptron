import cocotb
from cocotb.triggers import Timer


@cocotb.test()
async def test1(dut):
    """null values"""

    dut.source.value = "00001010"


    await Timer(1, unit="ns")

    assert dut.sink.value == "00101101"



