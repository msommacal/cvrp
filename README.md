# CVRP

The Capacitated Vehicle Routing Problem (CVRP) is a VRP which vehicles with limited carrying capacity need to pick up or deliver items at various locations. This project aims to solve the problem with an heuristic method.

![Screenshot](img/screenshot.png?raw=true "Screenshot")

The method used here is the method "route-first, cluster-second" described for the first time by Beasley in 1983. We first decide the order in which the customers are to be visited (the routing part of the process) and then partition the customers (cluster the customers) into sets that constitute feasible vehicle routes.

In this case, we assume that the vehicles all have the same capacity. Furthermore, the result depends on the first customer of the giant tour which is randomly chosen.

## Getting Started

These instructions will get you a copy of the project up and running on your local machine for development purposes.

### Prerequisites

Make sure that gcc is installed. To display the graphs, you will also need graphviz.

### Installing

First you have to clone the git project:

```
git clone https://github.com/msommacal/cvrp.git
```

Then you can compile the project using Make:

```
make
```

### Usage

The program relies on input files with the following format:
- line 1: number n of customers
- line 2: capacity of the vehicles
- line 3: n quantities requested from customers
- line 4 to 4+n: (n+1)\*(n+1) cost matrix

Example files can be found in the data folder.

To execute the software, you only need to use the following command:

```
./cvrp < data/data.txt
```

If you want to get a graph in DOT format as output you can use the following command instead:

```
./cvrp --graph < data/data.txt | dot -T x11
```

## License

This project is licensed under the GNU General Public License - see the [LICENSE.md](LICENSE.md) file for details.

## References

- Beasley, Je. « Route First—Cluster Second Methods for Vehicle Routing ». Omega, vol. 11, no 4, janvier 1983, p. 403‑08. DOI.org (Crossref), doi:10.1016/0305-0483(83)90033-6.
- Prins, Christian. The route-first cluster-second principle in vehicle routing. VIP, Oslo.
