import cocotb
from cocotb.triggers import Timer


@cocotb.test()
async def test1(dut):
    """(10 * 4) + 5 is greater than 16"""

    dut.source.value = "00001010"
    dut.selector.value = "00"


    await Timer(1, unit="ns")
    assert dut.sink.value == 1
    
@cocotb.test()
async def test7(dut):
    """(10 * 4) + 5 is greater than 16"""

    dut.source.value = "00000001"
    dut.selector.value = "00"


    await Timer(1, unit="ns")
    assert dut.sink.value == 0

@cocotb.test()
async def test8(dut):
    """(10 * 4) + 5 is greater than 16"""

    dut.source.value = "00000010"
    dut.selector.value = "00"


    await Timer(1, unit="ns")
    assert dut.sink.value == 0

@cocotb.test()
async def test9(dut):
    """(10 * 4) + 5 is greater than 16"""

    dut.source.value = "00000100"
    dut.selector.value = "00"


    await Timer(1, unit="ns")
    assert dut.sink.value == 1

@cocotb.test()
async def test10(dut):
    """(10 * 4) + 5 is greater than 16"""

    dut.source.value = "00001000"
    dut.selector.value = "00"


    await Timer(1, unit="ns")
    assert dut.sink.value == 1


@cocotb.test()
async def test2(dut):
    """change weight"""

    dut.source.value = "00000001"
    dut.selector.value = "01"


    await Timer(1, unit="ns")
    assert dut.weight.value == "001"

@cocotb.test()
async def test3(dut):
    """change offset"""

    dut.source.value = "00000001"
    dut.selector.value = "10"


    await Timer(1, unit="ns")
    assert dut.bias.value == "00000001"


@cocotb.test()
async def test4(dut):
    """change threshold"""

    dut.source.value = "00000001"
    dut.selector.value = "11"


    await Timer(1, unit="ns")
    assert dut.threshold.value == "00000001"

@cocotb.test()
async def test5(dut):
    """forward then back then forward again"""

    dut.source.value = "00010000" ##set the initial threshold
    dut.selector.value = "11"


    await Timer(1, unit="ns")

    dut.source.value = "00001010"
    dut.selector.value = "00"


    await Timer(1, unit="ns")
    assert dut.sink.value == 1

    dut.source.value = "00000001"
    dut.selector.value = "01"

    await Timer(1, unit="ns")
    assert dut.weight.value == "001"

    dut.source.value = "00000001"
    dut.selector.value = "10"

    await Timer(1, unit="ns")
    assert dut.bias.value == "00000001"


    print (dut.neuronProduct.value)
    print (dut.threshold.value)
    dut.source.value = "00000001"
    dut.selector.value = "00"

    await Timer(1, unit="ns")
    print(dut.sink.value)
    assert dut.sink.value == 0
    
@cocotb.test()
async def test6(dut):
    """null"""

    dut.source.value = "00000000"
    dut.selector.value = "00"


    await Timer(1, unit="ns")


    assert dut.sink.value == 0
