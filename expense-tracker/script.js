// 获取DOM元素
const addBtn = document.getElementById('add-btn');
const modal = document.getElementById('add-modal');
const saveBtn = document.getElementById('save-btn');
const cancelBtn = document.getElementById('cancel-btn');
const descriptionInput = document.getElementById('description');
const amountInput = document.getElementById('amount');
const transactionsList = document.getElementById('transactions-list');
const totalExpenseElement = document.getElementById('total-expense');
const balanceElement = document.getElementById('balance');

// 从localStorage获取数据
let transactions = JSON.parse(localStorage.getItem('transactions')) || [];
let initialBalance = parseFloat(localStorage.getItem('initialBalance')) || 1000; // 设置初始余额

// 更新显示
function updateDisplay() {
    // 清空列表
    transactionsList.innerHTML = '';
    
    // 计算总支出
    const totalExpense = transactions.reduce((total, transaction) => {
        return total + transaction.amount;
    }, 0);
    
    // 计算结余
    const balance = initialBalance - totalExpense;
    
    // 更新显示
    totalExpenseElement.textContent = `¥${totalExpense.toFixed(2)}`;
    balanceElement.textContent = `¥${balance.toFixed(2)}`;
    
    // 显示交易记录
    transactions.forEach(transaction => {
        const div = document.createElement('div');
        div.className = 'transaction-item';
        div.innerHTML = `
            <span>${transaction.description}</span>
            <span>¥${transaction.amount.toFixed(2)}</span>
        `;
        transactionsList.appendChild(div);
    });
    
    // 保存到localStorage
    localStorage.setItem('transactions', JSON.stringify(transactions));
}

// 添加新交易
function addTransaction(description, amount) {
    transactions.push({
        description,
        amount: parseFloat(amount),
        date: new Date()
    });
    updateDisplay();
}

// 事件监听
addBtn.addEventListener('click', () => {
    modal.style.display = 'block';
});

cancelBtn.addEventListener('click', () => {
    modal.style.display = 'none';
    descriptionInput.value = '';
    amountInput.value = '';
});

saveBtn.addEventListener('click', () => {
    const description = descriptionInput.value;
    const amount = parseFloat(amountInput.value);
    
    if (description.trim() === '' || isNaN(amount)) {
        alert('请填写有效的描述和金额！');
        return;
    }
    
    addTransaction(description, amount);
    modal.style.display = 'none';
    descriptionInput.value = '';
    amountInput.value = '';
});

// 点击modal外部关闭
window.addEventListener('click', (e) => {
    if (e.target === modal) {
        modal.style.display = 'none';
    }
});

// 初始化显示
updateDisplay();