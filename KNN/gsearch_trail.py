'''from googlesearch import search

# Define the query you want to search for
query = "Atif Aslam"

# Perform the Google search and retrieve the search results
search_results = str(search(query))
print("Results fetched")
print(type(search_results))
# Display the search results
for result in search_results:
    print(result)
exit()'''
from googlesearch import search
import webbrowser

# Ask for the search query
query = input("Input your query: ")

# Perform the Google search and retrieve the first search result URL
search_results = search(query, num_results=1)
first_result_url = next(search_results, None)

# Open the first search result in the web browser
if first_result_url:
    webbrowser.open(first_result_url)
else:
    print("No search results found.")


    
