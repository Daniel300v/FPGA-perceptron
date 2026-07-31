import cocotb
from cocotb.triggers import Timer


@cocotb.test()
async def test1(dut):
    """no shifts"""

    dut.barrelIn.value = "00001010"
    dut.totalShift.value = "000"
    
    await Timer(1, unit="ns")

    assert dut.barrelOut.value == "00001010"


@cocotb.test()
async def test2(dut):
    """one bit shift"""

    dut.barrelIn.value = "00001010"
    dut.totalShift.value = "001"
    
    await Timer(1, unit="ns")

    assert dut.barrelOut.value == "00010100"

@cocotb.test()
async def test3(dut):
    """two bit shift"""

    dut.barrelIn.value = "00001010"
    dut.totalShift.value = "010"
    
    await Timer(1, unit="ns")

    assert dut.barrelOut.value == "00101000"

@cocotb.test()
async def test4(dut):
    """three bit shift"""

    dut.barrelIn.value = "00001010"
    dut.totalShift.value = "011"
    
    await Timer(1, unit="ns")

    assert dut.barrelOut.value == "01010000"

@cocotb.test()
async def test5(dut):
    """four bit shift"""

    dut.barrelIn.value = "00001010"
    dut.totalShift.value = "100"
    
    await Timer(1, unit="ns")

    assert dut.barrelOut.value == "10100000"


@cocotb.test()
async def test6(dut):
    """five bit shift"""

    dut.barrelIn.value = "00001010"
    dut.totalShift.value = "101"
    
    await Timer(1, unit="ns")

    assert dut.barrelOut.value == "01000000"

@cocotb.test()
async def test7(dut):
    """six bit shift"""

    dut.barrelIn.value = "00001010"
    dut.totalShift.value = "110"
    
    await Timer(1, unit="ns")

    assert dut.barrelOut.value == "10000000"


@cocotb.test()
async def test8(dut):
    """seven bit shift"""

    dut.barrelIn.value = "00001010"
    dut.totalShift.value = "111"
    
    await Timer(1, unit="ns")

    assert dut.barrelOut.value == "00000000"
    
