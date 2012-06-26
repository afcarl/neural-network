This is a draft of what could possibly be a future C++ neural network library. I initially developed this library to embed it
into my project at university. This project was a simulation of predators and preys co-evolution who were controlled by feed-forward and continuous-time recurrent neural networks and evolved with genetic algorithms. It was successfully tested with
classifying problems and real-time autonomous agent controlling.

The library is lightweight, fast and cross-platform. Feel free to contact me for any questions or suggestions.

Installation
------------

Dependencies:

* **git 1.7.3** or newer
* **gcc 4.2** or newer

Download and compile the sources:

~~~ sh
$ git clone git://github.com/allister633/neural-network.git
$ cd neural-network && make
~~~

This will generate a static library, to link against it:

~~~ sh
$ g++ main.cpp -L. -lneural-network
~~~

Where -L specifies the path where the library is located, in this example it's in the current folder.

Perceptron
----------

The single-layer perceptron is a simple linear classifier. For a given input, usually a real-valued vector, it will output
a binary value. The example folder includes an example of how we can train a perceptron to act as a logic OR gate.

By default, weights and biases are initialized with a random value between -1.0 and 1.0. The default learning rate is 0.1.

Author
------
Mickael Lebedev :: mickael.lebedev@gmail.com