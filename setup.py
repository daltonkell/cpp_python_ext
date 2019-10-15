from distutils.core import setup, Extension

def main():
    setup(
        name='cpp_python_ext',
        version='0.0.1',
        description='Python interface to C program',
        author='Dalton Kell',
        ext_modules=[
            Extension('getone', ['getonemodule.cpp'])
        ]
    )

if __name__ == "__main__":
    main()
