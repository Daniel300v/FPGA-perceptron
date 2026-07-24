import cocotb
from cocotb.triggers import Timer


@cocotb.test()
async def test1(dut):
    """null values"""

    dut.A.value = 0
    dut.B.value = 0
    dut.C.value = 0

    await Timer(1, units="ns")

    assert dut.SUM.value == 0
    assert dut.CARRY.value == 0


@cocotb.test()
async def test2(dut):
    """full values"""

    dut.A.value = 1
    dut.B.value = 1
    dut.C.value = 1

    await Timer(1, units="ns")

    assert dut.SUM.value == 1
    assert dut.CARRY.value == 1