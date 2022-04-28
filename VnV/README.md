# Folder structure

analysis : Code for analyzing data
data : the raw data (stored here for openness and ease of access for all users)
results : the results of our analysis (csvs, graphs, and other VnV 'deliverables')

# Tutorial

## Step 0: Read the testing plan of the final report

## Step 1: Open the Virtual Machines and open a terminal in each
![image](https://user-images.githubusercontent.com/40191185/165826368-c5caab6c-7819-469b-863b-a4dc5056833c.png)

## Step 2: Open Settings > Network and connect each machine to a different adapter (these should be the ethernet->usb-c adapters you use)
![image](https://user-images.githubusercontent.com/40191185/165826745-2f93958b-cc08-4e53-8dfb-67905eab4e51.png)

## Step 3: Run 'run_test.sh' on Virtual Machine 1
![image](https://user-images.githubusercontent.com/40191185/165827705-222f69fa-f8d2-4f60-ace7-9dfeca0f4dad.png)

## Step 4: Run 'run_test.sh' on Virtual Machine 2
Argument 1 is the name of the test

Argument 2 is the number of trials to run

![image](https://user-images.githubusercontent.com/40191185/165827832-c1f5ca39-afa3-49f8-9495-66c40015d4e3.png)


## Step 5: Transfer the data from '/home/microp2/shared/your_test_name' to your laptop
(hint: you should link the 'shared' folder to your local host machine)

## Step 6: Transfer the data to the '/VnV/data' folder

## Step 7: Run the Jupyter Notebook 'VnV/analysis/Munge and Initial Analysis.ipynb'

## Step 8: Change the raw_data_paths to your new data, naming the key after the data you are analyzing
![image](https://user-images.githubusercontent.com/40191185/165828427-00688e6f-8cfb-4284-89e0-482662eff915.png)

## Step 9: Run all the cells of the notebook
Your throughput, latency, and error will saved in `VnV/results' as .csv files


If you are good with Pandas, you should edit the notebook itself to perform additional analysis.


