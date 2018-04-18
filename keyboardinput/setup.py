#Credit goes to the pypa sample setup.py file
from setuptools import setup, find_packages

setup(
    name='keyboardinput',  # Required

    version='1.0.0',  # Required

    description='Curses-based input wrapper for sending commands to Arduino Rover',  # Required

    url='https://github.com/LukasVannStruth/STEM-Tethered-Rover.git',  # Optional
    author='Lukas Vann Struth',  
    author_email='lvannstruth@gmail.com', 

    classifiers=[
        'Development Status :: 4 - Beta',
        'Intended Audience :: Developers',
        'Topic :: Software Development :: Embedded Systems',
        'License :: OSI Approved :: MIT License',
        'Programming Language :: Python :: 3.6',
    ],
    packages=['keyboardinput'],  # Required
    install_requires=['pyserial'],  # Optional
    entry_points={  # Optional
        'console_scripts': [
            'keyboardinput = keyboardinput:main',
        ],
    },
)