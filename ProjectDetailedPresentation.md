[EN] 
YILDIZ TECHNICAL UNIVERSITY FACULTY OF ELECTRICAL AND ELECTRONICS ENGINEERING 2023-2024 ACADEMIC YEAR MULTIDISCIPLINARY DESIGN PROJECT
TOPIC: Placement of 2D Objects within a Defined Area Using a 3-Axis Robot
Assoc. Prof. Dr. Umut Engin AYTEN

CONTENT:
Objective
Scope and Minimum Deliverables
Bonus Deliverables
Evaluation
Detailed Explanation of the Topic
References

OBJECTIVE OF THE PROJECT

The primary goal of this project is to optimally place two-dimensional objects within a predefined two-dimensional area in such a way that the objects occupy the minimum possible space.

![1](https://github.com/lrzblr/MultidisciplinaryDesignProject/assets/133981055/3952e903-a853-40df-9ef9-197017ccb7fc)  

To achieve this goal, a literature review will be conducted, and an optimization method will be selected. Using the chosen optimization method, the placement of two-dimensional objects of varying sizes onto a predefined paper area will be carried out. The success of the selected optimization method will be evaluated based on the percentage of unoccupied areas, and a comparison with the existing literature will be made. For this task, one of the benchmark datasets provided in the literature will be used.


In addition to the primary objective mentioned earlier, this project aims to design a robotic system capable of three-axis motion.

![image](https://github.com/lrzblr/MultidisciplinaryDesignProject/assets/133981055/24b352bc-ec96-4c6c-97a1-a4d0effd4872)  ![image](https://github.com/lrzblr/MultidisciplinaryDesignProject/assets/133981055/78838a6b-92f9-437b-8a42-9e75a1fcb923)


With this robotic design, the project aims to perform cutting or packaging operations on objects placed within a constrained area (due to mechanical complexities and occupational safety concerns,the actual cutting or packaging operations will be simulated by a three-axis robot drawing 2D objects only within the specified area).

SCOPE AND MINIMUM DELIVERABLES OF THE PROJECT

The steps and minimum deliverables of the project are listed below:

Review of methods in the literature for optimization process.
Implementation of the selected optimization method's software.
Conducting tests of the optimization software's performance with benchmarks and determining success rate.
Mechanical design of the three-axis robot.
Implementation of electronic hardware for the three-axis robot.
Development of embedded system software to perform drawing of 2D objects within the specified area using the three-axis robot.

BONUS DELIVERABLES

Defining labels in shapes other than rectangular, such as circular or partially circular forms.
Exploring new optimization approaches to enhance existing optimization methods in the literature.
Developing a unique design for the robotic process defined in this project.
Using image processing techniques to assess the success of label cutting or packaging placement after physical execution.


PROJECT EVALUATION

Detailed execution of literature review
Implementation of the selected optimization method's software
Comparison of the achieved optimization performance with literature
Design capability of mechanical, electronic hardware, and embedded system software for the three-axis robot
Solution methods and their applicability, efficiency
Solution methods that can create differentiation
Team collaboration and planning in the project
Project management plan and final report
Presentation of the project in project market

PROJECT DETAILS

TOPIC: Placement of 2D Objects within a Defined Area Using a 3-Axis Robot

The Cutting Stock Problem (CSP) was first introduced by Gilmore and Gomory in 1961 [1].
Dyckhoff (1990) published an article on cutting and packing problems to classify research and publications accurately.
Despite differences in nomenclature arising from the problem's objectives, the solution approaches and variants are similar.

Cutting and packing problems define patterns consisting of combinations of large items and small elements. In packing problems,
large items are defined as empty, needing to be filled with smaller items. Cutting problems involve cutting large items into smaller pieces.
The primary aim of most cutting and packing problems is to minimize waste or cutting loss. Dyckhoff (1990) emphasizes the strong relationship
between cutting and packing problems arising from material and spatial duality [2].

This problem has been extensively researched for many years due to its numerous applications in the cutting and packing industry,
including wood, glass, fabric industries, newspaper layouts, VLSI circuit placement, etc. The 2D rectangular packing and cutting problem has been
shown to be NP-hard (Hochbaum and Maass, 1985) [3].

There are various approaches to solving this problem depending on its objective. As a result, categorization studies have been conducted with various articles.

![image](https://github.com/lrzblr/MultidisciplinaryDesignProject/assets/133981055/9ae626b6-720d-4f78-bd96-80dffc554891)

Non-orthogonal placement [4]

![image](https://github.com/lrzblr/MultidisciplinaryDesignProject/assets/133981055/a9bdbde0-9607-4e85-9f34-992a815226f7)

Placement suitable and unsuitable for guillotine cutting [4]

![image](https://github.com/lrzblr/MultidisciplinaryDesignProject/assets/133981055/e14781d6-9ea6-41aa-a448-9e820e133dd8)

Placement according to two-level and three-level guillotine cutting [4]

![image](https://github.com/lrzblr/MultidisciplinaryDesignProject/assets/133981055/43a0b63e-9120-4860-8555-cc08dd429b9f)

Placement according to exact two-level and non-exact two-level guillotine cutting [4]

![image](https://github.com/lrzblr/MultidisciplinaryDesignProject/assets/133981055/10cc8076-d06c-4b83-947d-a91011d864e1)

General classification of cutting and packing problems [5]

In the context of the MDDP course, the dataset provided by Hopper and Turton will be used for testing operations [6]. This dataset includes 21 examples across 7 classes, with 3 examples per problem class.

![image](https://github.com/lrzblr/MultidisciplinaryDesignProject/assets/133981055/73cd3bfc-21b2-40b4-b796-adfb69432958)

To demonstrate the success of the optimization process, all classes and examples from the dataset must be utilized. However, only the data from the class named C1 will be used for drawing with the robot you will design.

References [5] provides a detailed examination, and the dataset has been shared on GitHub. The relevant dataset can be downloaded from this page: 2D Cutting and Packing Dataset. Additionally, the department pages will also share information about this dataset.

For solving this optimization problem, numerous methods have been proposed in the literature including linear and non-linear programming methods, heuristic and metaheuristic methods, genetic algorithms, particle swarm algorithms, and various machine learning algorithms.

After conducting a detailed literature review within the scope of the project, one of these methods will be selected. The algorithm corresponding to the chosen method will then be implemented in the programming language selected by the group.

Metrics for comparison can be identified from the literature to evaluate the optimization success. The success of the study based on these performance metrics will be presented comparatively with existing literature studies.


After completing the optimization process, a robotic design will be developed to draw the placement plan obtained on paper. The designed robot must be three-axis due to the nature of the problem.

Designs can be realized considering cost factors through 3D printers or using prefabricated parts. Selection of motors for the motion mechanism will be left to the CDTP groups. Depending on the chosen motor, electronic hardware, controller design, and software for the electronic system will be implemented.

![image](https://github.com/lrzblr/MultidisciplinaryDesignProject/assets/133981055/4057de6e-8c46-435b-81bb-cbcffbdbbd1f)  ![image](https://github.com/lrzblr/MultidisciplinaryDesignProject/assets/133981055/8be6ee05-1594-4fce-8a09-bf789e606241)



Development boards, single-board computers, or custom-designed microcontroller-based hardware can be used for electronic hardware.

REFERENCES
[1] Gilmore, P. C., & Gomory, R. E. (1961). A linear programming approach to the cutting-stock problem. Operations research, 9(6), 849-859.

[2] Dyckhoff, H. (1990). A typology of cutting and packing problems. European Journal of Operational Research, 44(2), 145-159.

[3] Hochbaum, D. S., & Maass, W. (1985). Approximation schemes for covering and packing problems in image processing and VLSI. Journal of the Association for Computing Machinery, 32(1), 130–136.

[4] Óscar Oliveira, Dorabela Gamboa, Elsa Silva, 'An introduction to the two-dimensional rectangular cutting and packing problem', International transactions in operational research, 2023.

[5] Álvaro Luiz Neuenfeldt Júnior, 'The Two-Dimensional Rectangular Strip Packing Problem', PhD Thesis, 2017.

[6] E. Hopper and B. C. H. Turton, Empirical investigation of meta-heuristic and heuristic algorithms for a 2D packing problem, European Journal of Operational Research, 128:1 (2001) 34–57.




