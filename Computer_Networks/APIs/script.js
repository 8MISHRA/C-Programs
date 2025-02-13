document.getElementById("submitButton").addEventListener("click", function() {
    const text = document.getElementById("textInput").value;
    
    fetch("https://yourserver.com/submit", {
        method: "POST",
        headers: {
            "Content-Type": "application/json"
        },
        body: JSON.stringify({ text: text })
    })
    .then(response => response.json())
    .then(data => console.log("Success:", data))
    .catch(error => console.error("Error:", error));
});
