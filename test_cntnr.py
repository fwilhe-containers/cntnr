import pytest
import subprocess
import json

def cntnr(args):
    output = subprocess.run(["./cntnr"] + args, capture_output=True)
    stdout = output.stdout.decode("utf-8").rstrip()
    stderr = output.stderr.decode("utf-8").rstrip()
    return (stdout, stderr)

def test_run_apps_without_args():
    stdout, stderr = cntnr(['./app'])
    parsed_stdout = json.loads(stdout)
    assert parsed_stdout['args'] == '1'
    assert parsed_stdout['uid'] == '65534'
    assert stderr == ""

def test_run_apps_with_args():
    stdout, stderr = cntnr(['./app', 'with', 'some', 'args'])
    parsed_stdout = json.loads(stdout)
    assert parsed_stdout['args'] == '4'
    assert parsed_stdout['uid'] == '65534'
    assert stderr == ""

def test_run_python_uid():
    stdout, stderr = cntnr(['python', 'print_uid.py'])
    assert stdout == "65534"
    assert stderr == ""

# def test_run_python_username():
#     stdout, stderr = cntnr(['python', 'print_username.py'])
#     assert stdout == "nobody"
#     assert stderr == ""
