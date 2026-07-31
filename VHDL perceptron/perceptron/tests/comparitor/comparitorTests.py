import cocotb
from cocotb.triggers import Timer


@cocotb.test()
async def test1(dut):
    """null values"""

    dut.perceved.value = "00000000"
    dut.static.value = "00000000"


    await Timer(1, unit="ns")

    assert dut.activation.value == 1


@cocotb.test()
async def test2(dut):
    """1 v 0"""

    dut.perceved.value = "00000001"
    dut.static.value = "00000000"


    await Timer(1, unit="ns")

    assert dut.activation.value == 1

@cocotb.test()
async def test3(dut):
    """0 v 1"""

    dut.perceved.value = "00000000"
    dut.static.value = "00000001"


    await Timer(1, unit="ns")

    assert dut.activation.value == 0


@cocotb.test()
async def test4(dut):
    """00101101 v 00010000"""

    dut.perceved.value = "00101101"
    dut.static.value = "00010000"


    await Timer(1, unit="ns")

    assert dut.activation.value == 1

