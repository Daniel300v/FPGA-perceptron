import cocotb
from cocotb.triggers import Timer
import random

@cocotb.test()
async def test1(dut):
    """null values"""

    dut.inA.value = "00000000"
    dut.inB.value = "00000000"

    await Timer(1, unit="ns")

    assert dut.SUM.value == "00000000"


@cocotb.test()
async def test2(dut):
    """4 + 2 values"""

    dut.inA.value = "00000100"
    dut.inB.value = "00000010"

    await Timer(1, unit="ns")

    assert dut.SUM.value == "00000110"

@cocotb.test()
async def test3(dut):
    """random values"""

    for _ in range(10000):

        a = random.randint(0,255)
        b = random.randint(0,255)
        dut.inA.value = a 
        dut.inB.value = b 

        await Timer(1, unit="ns")

        assert dut.SUM.value == (a+b) & 0xff
