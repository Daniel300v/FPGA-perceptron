import os
from pathlib import Path

from cocotb_tools.runner import get_runner


def test_my_design_runner():
    sim = os.getenv("SIM", "nvc")

    proj_path = Path(__file__).resolve().parent

    sources = [proj_path / "src/perceptron.vhd",
               proj_path / "src/halfAdder.vhd",
               proj_path / "src/fullAdder.vhd",
               proj_path / "src/eightBitAdder.vhd",
               proj_path / "src/oneBitLeftShift.vhd",
               proj_path / "src/twoBitLeftShift.vhd",
               proj_path / "src/fourBitLeftShift.vhd",
               proj_path / "src/barrelShifter.vhd"]

    runner = get_runner(sim)
    runner.build(
        sources=sources,
        hdl_toplevel="perceptron",
    )

    #runner.test(hdl_toplevel="halfAdder", test_module="halfAdderTests,")
    #runner.test(hdl_toplevel="fullAdder", test_module="fullAdderTests,")
    #runner.test(hdl_toplevel="eightBitAdder", test_module="eightBitAdder,")
    #runner.test(hdl_toplevel="oneBitLeftShift", test_module="oneBitLeftShiftTests,")
    #runner.test(hdl_toplevel="twoBitLeftShift", test_module="twoBitLeftShiftTests,")
    #runner.test(hdl_toplevel="fourBitLeftShift", test_module="fourBitLeftShiftTests,")
    #runner.test(hdl_toplevel="barrelShifter", test_module="barrelTests,")
    runner.test(hdl_toplevel="perceptron", test_module="perceptronTests,")


if __name__ == "__main__":
    test_my_design_runner()
