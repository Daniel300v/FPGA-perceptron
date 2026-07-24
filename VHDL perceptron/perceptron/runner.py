import os
from pathlib import Path

from cocotb_tools.runner import get_runner


def test_my_design_runner():
    sim = os.getenv("SIM", "nvc")

    proj_path = Path(__file__).resolve().parent

    sources = [proj_path / "src/perceptron.vhd",
               proj_path / "src/halfAdder.vhd",
               proj_path / "src/fullAdder.vhd",
               proj_path / "src/eightBitAdder.vhd"]

    runner = get_runner(sim)
    runner.build(
        sources=sources,
        hdl_toplevel="perceptron",
    )

    #runner.test(hdl_toplevel="halfAdder", test_module="halfAdderTests,")
    #runner.test(hdl_toplevel="fullAdder", test_module="fullAdderTests,")
    runner.test(hdl_toplevel="eightBitAdder", test_module="eightBitAdder,")


if __name__ == "__main__":
    test_my_design_runner()
