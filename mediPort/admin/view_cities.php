<?php session_start();
	include 'includes/db.php';
	if(isset($_SESSION['user']) && isset($_SESSION['password']) == true){
		$sel_sql = "SELECT * FROM users WHERE user_email = '$_SESSION[user]' AND user_password = '$_SESSION[password]'";
		if($run_sql = mysqli_query($conn, $sel_sql)){
			while($rows = mysqli_fetch_assoc($run_sql)){
				if(mysqli_num_rows($run_sql) == 1 ){
					if($rows['role'] == 'admin'){
					} else {
						header('Location:../index.php');
					}
				} else{
					header('Location:../index.php');
				}
			}
		}
	} else {
		header('Location:../index.php');
	}
	
	$per_page = 10;
	if(isset($_GET['page'])){
		$page = $_GET['page'];
	} else{
		$page = 1;
	}
	$start_from = ($page-1) * $per_page;
	
?>
<!DOCTYPE html>
<html>
	<head>
		<title>Admin Panel</title>
		<link rel="stylesheet" href="../../bootstrap/css/bootstrap.css">
		<script src="../../js/jquery.js"></script>
		<script src="../../bootstrap/js/bootstrap.js"></script>
		<script>
			
		</script>
	</head>
	<body>
		<?php include 'includes/header.php';?>
		<div style="width:50px;height:50px;"></div>
		<?php include 'includes/sidebar.php';?>
		<div class="col-lg-10">
		<div style="width:50px;height:50px;"></div>
			<!------ Users Area --->
			<!------ Post lists Starts----->
			<div class="panel panel-primary">
				<div class="panel-heading"><h3>Cities</h3></div>
				<div class="panel-body">
					<table class="table table-striped">
						<thead>
							<tr>
								<th>S.No</th>
								<th>City Name</th>
							</tr>
							
						</thead>
						<tbody>
							<?php
								//$sql = "SELECT * FROM posts ORDER BY ID DESC";
								$sql = "SELECT * FROM city order by c_name LIMIT $start_from,$per_page";
								$run = mysqli_query($conn,$sql);
								$i=1;
								while($rows = mysqli_fetch_assoc($run)){
									echo '
									<tr>
										<td>'.$i.'</td>
										<td>'.$rows['c_name'].'</td>
									</tr>
									';
									$i++;
								}
							?>
							
							
						</tbody>
					</table>
				</div>
			</div>
			<div class="text-center">
				<ul class="pagination">
				<?php
					$pagination_sql = "SELECT * FROM city";
					$run_pagination = mysqli_query($conn, $pagination_sql);

					$count = mysqli_num_rows($run_pagination);
					
					$total_pages = ceil($count/$per_page);
					
					for($i=1;$i<=$total_pages;$i++){
						echo '<li><a href="view_cities.php?page='.$i.'">'.$i.'</a></li>';
					}
					
				?>			
				</ul>

			</div>
			
		</div>
		<footer></footer>
	</body>
</html>