import cocotb
from cocotb.triggers import Timer


@cocotb.test()
async def test1(dut):
    """null shift"""

    dut.inA.value = "00001010"
    dut.shift.value = 0

    await Timer(1, unit="ns")

    assert dut.shifted.value == "00001010"

@cocotb.test()
async def test2(dut):
    """yes shift"""

    dut.inA.value = "00001010"
    dut.shift.value = 1

    await Timer(1, unit="ns")

    assert dut.shifted.value == "00010100"
