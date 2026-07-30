// Product Array

const products = [
    { id: 1, name: "Laptop", price: 50000 },
    { id: 2, name: "Mouse", price: 500 },
    { id: 3, name: "Keyboard", price: 1000 },
    { id: 4, name: "Headphone", price: 2000 },
    { id: 5, name: "Mobile", price: 15000 },
    { id: 6, name: "Tablet", price: 20000 }
];

// Shopping Cart

let cart = [];

// Add Product to Cart

function addToCart(id) {

    const product = products.find(item => item.id === id);

    if (product) {

        cart.push(product);

        alert(product.name + " Added to Cart");

        displayCart();
    }
}

// Display Cart

function displayCart() {

    const cartBody = document.getElementById("cart-body");

    cartBody.innerHTML = "";

    let total = 0;

    cart.forEach((item, index) => {

        total += item.price;

        cartBody.innerHTML += `
            <tr>
                <td>${item.id}</td>
                <td>${item.name}</td>
                <td>₹${item.price}</td>
                <td>
                    <button class="remove-btn" onclick="removeItem(${index})">
                        Remove
                    </button>
                </td>
            </tr>
        `;
    });

    document.getElementById("total").innerHTML = "Total : ₹" + total;
}

// Remove Product

function removeItem(index) {

    if (confirm("Remove this item from cart?")) {

        cart.splice(index, 1);

        displayCart();
    }
}

// Checkout

function checkout() {

    if (cart.length === 0) {

        alert("Your cart is empty!");

        return;
    }

    let total = 0;

    cart.forEach(item => {
        total += item.price;
    });

    alert(
        "Final Bill = ₹" +
        total +
        "\n\nThank You for Shopping!"
    );

    cart = [];

    displayCart();
}